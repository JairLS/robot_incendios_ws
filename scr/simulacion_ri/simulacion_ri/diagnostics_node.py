#!/usr/bin/env python3
"""
Diagnostics Node - Robot de Incendios v2.0
Publica stats del sistema (CPU/RAM/Temp/Throttling) y FPS de sensores.

Topics de salida:
  /diagnostics_robot                std_msgs/String   (JSON con todo)

  /diagnostics/cpu_pct              std_msgs/Float32
  /diagnostics/ram_pct              std_msgs/Float32
  /diagnostics/temp_c               std_msgs/Float32  (solo si disponible)
  /diagnostics/uptime_s             std_msgs/Int32
  /diagnostics/throttled_now        std_msgs/Bool     (solo si disponible)
  /diagnostics/under_voltage_now    std_msgs/Bool     (solo si disponible)
  /diagnostics/fps/scan             std_msgs/Float32
  /diagnostics/fps/camera           std_msgs/Float32
  /diagnostics/fps/thermal          std_msgs/Float32
  /diagnostics/fps/odom             std_msgs/Float32

Topics monitoreados (input):
  /scan, /camera/image_raw/compressed, /thermal/image_raw/compressed, /odom
"""

import json
import time
import subprocess

import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Float32, Bool, Int32
from sensor_msgs.msg import LaserScan, CompressedImage
from nav_msgs.msg import Odometry

try:
    import psutil
    HAS_PSUTIL = True
except ImportError:
    HAS_PSUTIL = False


class DiagnosticsNode(Node):
    """Nodo de diagnostico: agrega stats del sistema + FPS de sensores."""

    WINDOW_S = 2.0

    # Mapeo topic monitoreado -> nombre corto para el topic FPS de salida
    FPS_SHORT_NAMES = {
        '/scan':                          'scan',
        '/camera/image_raw/compressed':   'camera',
        '/thermal/image_raw/compressed':  'thermal',
        '/odom':                          'odom',
    }

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

        # Suscriptores
        for topic, msg_type in self.topics_monitored.items():
            self.create_subscription(
                msg_type,
                topic,
                lambda msg, t=topic: self._on_message(t),
                10
            )
            self.get_logger().info(f'Monitoreando: {topic}')

        # --- Publishers ---
        # Topic original con JSON (compatible hacia atras)
        self.pub_json = self.create_publisher(String, '/diagnostics_robot', 10)

        # Publishers individuales (para dashboard en Foxglove)
        self.pub_cpu       = self.create_publisher(Float32, '/diagnostics/cpu_pct', 10)
        self.pub_ram       = self.create_publisher(Float32, '/diagnostics/ram_pct', 10)
        self.pub_temp      = self.create_publisher(Float32, '/diagnostics/temp_c', 10)
        self.pub_uptime    = self.create_publisher(Int32,   '/diagnostics/uptime_s', 10)
        self.pub_throttled = self.create_publisher(Bool,    '/diagnostics/throttled_now', 10)
        self.pub_undervolt = self.create_publisher(Bool,    '/diagnostics/under_voltage_now', 10)

        # FPS por topic (publishers individuales con nombres cortos)
        self.pub_fps = {
            topic: self.create_publisher(Float32, f'/diagnostics/fps/{short}', 10)
            for topic, short in self.FPS_SHORT_NAMES.items()
        }

        # Tiempo de inicio
        self.start_time = time.time()

        # Inicializa contador CPU de psutil
        if HAS_PSUTIL:
            psutil.cpu_percent(interval=None)

        # Timer principal
        self.create_timer(self.WINDOW_S, self._publish_diagnostics)

        self.get_logger().info(
            f'Diagnostics activo: /diagnostics_robot (JSON) + /diagnostics/* (campos) cada {self.WINDOW_S}s'
        )

    # ---------- Callbacks ----------

    def _on_message(self, topic):
        self.msg_counts[topic] += 1
        self.last_msg_time[topic] = time.time()

    # ---------- Helpers de sistema ----------

    def _read_temp(self):
        try:
            with open('/sys/class/thermal/thermal_zone0/temp', 'r') as f:
                return float(f.read().strip()) / 1000.0
        except Exception:
            return None

    def _read_throttled(self):
        """
        Bits importantes (segun docs RPi):
          0x1     under_voltage_now       <- LiPo baja causa esto
          0x2     freq_capped_now
          0x4     throttled_now           <- CPU bajada de frecuencia ahora
          0x10000 under_voltage_ever
          0x40000 throttled_ever
        """
        try:
            result = subprocess.run(
                ['vcgencmd', 'get_throttled'],
                capture_output=True, text=True, timeout=1
            )
            raw = result.stdout.strip().split('=')[1]
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
        stats = {
            'cpu_pct': None,
            'ram_pct': None,
            'temp_c': None,
            'throttled': None,
        }
        if HAS_PSUTIL:
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
                last_age[topic] = None

        # Reset contadores
        for topic in self.msg_counts:
            self.msg_counts[topic] = 0

        sys_stats = self._system_stats()
        uptime = int(now - self.start_time)

        # --- 1. Publicar JSON (compatible hacia atras) ---
        diag = {
            'timestamp':      round(now, 2),
            'uptime_s':       uptime,
            'system':         sys_stats,
            'fps_hz':         fps,
            'last_msg_age_s': last_age,
        }
        msg = String()
        msg.data = json.dumps(diag)
        self.pub_json.publish(msg)

        # --- 2. Publicar campos individuales (para dashboard) ---
        # CPU / RAM: solo si psutil disponible
        if sys_stats['cpu_pct'] is not None:
            self.pub_cpu.publish(Float32(data=float(sys_stats['cpu_pct'])))
        if sys_stats['ram_pct'] is not None:
            self.pub_ram.publish(Float32(data=float(sys_stats['ram_pct'])))

        # Temperatura: solo si /sys disponible (RPi si, WSL2 no)
        if sys_stats['temp_c'] is not None:
            self.pub_temp.publish(Float32(data=float(sys_stats['temp_c'])))

        # Uptime: siempre
        self.pub_uptime.publish(Int32(data=uptime))

        # Throttling: solo si vcgencmd disponible (RPi si, WSL2 no)
        if sys_stats['throttled'] is not None:
            thr = sys_stats['throttled']
            self.pub_throttled.publish(Bool(data=thr['throttled_now']))
            self.pub_undervolt.publish(Bool(data=thr['under_voltage_now']))

        # FPS: siempre publicamos los 4 (0.0 si nadie ha mandado)
        for topic, hz in fps.items():
            if topic in self.pub_fps:
                self.pub_fps[topic].publish(Float32(data=float(hz)))


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