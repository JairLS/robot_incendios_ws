#!/usr/bin/env python3
"""
Diagnostics Node - Robot de Incendios v2.0
Publica stats del sistema (CPU/RAM/Temp/Throttling) y FPS de sensores
en /diagnostics_robot cada 2 segundos como JSON dentro de std_msgs/String.

Topics monitoreados:
  /scan                                 (LaserScan, sensor_msgs)
  /camera/image_raw/compressed          (CompressedImage, sensor_msgs)
  /thermal/image_raw/compressed         (CompressedImage, sensor_msgs)
  /odom                                 (Odometry, nav_msgs)
"""

import json
import time
import subprocess

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import LaserScan, CompressedImage
from nav_msgs.msg import Odometry

try:
    import psutil
    HAS_PSUTIL = True
except ImportError:
    HAS_PSUTIL = False


class DiagnosticsNode(Node):
    """Nodo de diagnóstico: agrega stats del sistema + FPS de sensores."""

    # Ventana de tiempo (segundos) sobre la cual calcular FPS
    WINDOW_S = 2.0

    def __init__(self):
        super().__init__('diagnostics_node')

        if not HAS_PSUTIL:
            self.get_logger().warn(
                'psutil no esta instalado. CPU/RAM no estaran disponibles. '
                'Instala con: pip3 install psutil'
            )

        # Topics a monitorear: {topic_name: msg_type}
        self.topics_monitored = {
            '/scan':                          LaserScan,
            '/camera/image_raw/compressed':   CompressedImage,
            '/thermal/image_raw/compressed':  CompressedImage,
            '/odom':                          Odometry,
        }

        # Estado por topic
        self.msg_counts = {t: 0 for t in self.topics_monitored}
        self.last_msg_time = {t: None for t in self.topics_monitored}

        # Suscriptores: callback solo cuenta y marca timestamp
        for topic, msg_type in self.topics_monitored.items():
            self.create_subscription(
                msg_type,
                topic,
                lambda msg, t=topic: self._on_message(t),
                10
            )
            self.get_logger().info(f'Monitoreando: {topic}')

        # Publisher
        self.pub = self.create_publisher(String, '/diagnostics_robot', 10)

        # Para uptime
        self.start_time = time.time()

        # Primer llamado a cpu_percent inicializa el contador interno
        if HAS_PSUTIL:
            psutil.cpu_percent(interval=None)

        # Timer principal
        self.create_timer(self.WINDOW_S, self._publish_diagnostics)

        self.get_logger().info(
            f'Diagnostics activo: publicando en /diagnostics_robot cada {self.WINDOW_S}s'
        )

    # ---------- Callbacks ----------

    def _on_message(self, topic):
        """Callback uniforme: incrementa contador y marca tiempo."""
        self.msg_counts[topic] += 1
        self.last_msg_time[topic] = time.time()

    # ---------- Helpers de sistema ----------

    def _read_temp(self):
        """Temperatura del SoC en grados Celsius (lee /sys/...)."""
        try:
            with open('/sys/class/thermal/thermal_zone0/temp', 'r') as f:
                return float(f.read().strip()) / 1000.0
        except Exception:
            return None

    def _read_throttled(self):
        """
        Lee el estado de throttling de la RPi via vcgencmd.
        Devuelve dict con flags activos o None si falla.

        Bits importantes (segun docs RPi):
          0x1     under_voltage_now       <- LiPo baja causa esto
          0x2     freq_capped_now
          0x4     throttled_now           <- CPU bajada de frecuencia ahora
          0x10000 under_voltage_ever      <- ocurrio alguna vez desde boot
          0x40000 throttled_ever
        """
        try:
            result = subprocess.run(
                ['vcgencmd', 'get_throttled'],
                capture_output=True, text=True, timeout=1
            )
            raw = result.stdout.strip().split('=')[1]  # "0x0" o "0x50005"
            flags = int(raw, 16)
            return {
                'under_voltage_now':   bool(flags & 0x1),
                'freq_capped_now':     bool(flags & 0x2),
                'throttled_now':       bool(flags & 0x4),
                'under_voltage_ever':  bool(flags & 0x10000),
                'throttled_ever':      bool(flags & 0x40000),
                'raw_hex': raw,
            }
        except Exception:
            return None

    def _system_stats(self):
        """CPU%, RAM%, Temp, Throttling."""
        stats = {
            'cpu_pct': None,
            'ram_pct': None,
            'temp_c': None,
            'throttled': None,
        }

        if HAS_PSUTIL:
            # interval=None usa el delta desde la ultima llamada (no bloquea)
            stats['cpu_pct'] = psutil.cpu_percent(interval=None)
            stats['ram_pct'] = psutil.virtual_memory().percent

        temp = self._read_temp()
        if temp is not None:
            stats['temp_c'] = round(temp, 1)

        stats['throttled'] = self._read_throttled()

        return stats

    # ---------- Publicacion ----------

    def _publish_diagnostics(self):
        now = time.time()

        # FPS y edad del ultimo mensaje por topic
        fps = {}
        last_age = {}
        for topic, count in self.msg_counts.items():
            fps[topic] = round(count / self.WINDOW_S, 1)
            if self.last_msg_time[topic] is not None:
                last_age[topic] = round(now - self.last_msg_time[topic], 1)
            else:
                last_age[topic] = None  # nunca llego mensaje

        # Reset contadores para la siguiente ventana
        for topic in self.msg_counts:
            self.msg_counts[topic] = 0

        diag = {
            'timestamp':     round(now, 2),
            'uptime_s':      int(now - self.start_time),
            'system':        self._system_stats(),
            'fps_hz':        fps,
            'last_msg_age_s': last_age,
        }

        msg = String()
        msg.data = json.dumps(diag)
        self.pub.publish(msg)


def main():
    rclpy.init()
    node = DiagnosticsNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
