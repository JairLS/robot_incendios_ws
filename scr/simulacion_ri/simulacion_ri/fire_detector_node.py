#!/usr/bin/env python3
"""
Fire Detector Node - Robot de Incendios v2.0

Subscribe: /thermal/max_temp (Float32)
Publica:   /fire_markers (visualization_msgs/MarkerArray)

Logica:
  - T < 26C: ambiente, ignorar
  - 26 <= T <= 36C: persona/animal, marker VERDE
  - T > 36C: foco de calor, marker ROJO

Cada deteccion crea un circulo difuso (cilindro plano) a 3.5m enfrente del robot
en el mapa SLAM (frame "map"). Markers permanentes y acumulativos con throttling:
  - Minimo 3 segundos entre markers
  - Minimo 0.5 metros de distancia entre markers consecutivos
"""

import math

import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
import rclpy.time

from std_msgs.msg import Float32, ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray

import tf2_ros


class FireDetectorNode(Node):
    """Detecta focos de calor y los publica como markers acumulativos en el mapa."""

    # Umbrales de temperatura (Celsius)
    TEMP_MIN_DETECT  = 26.0   # debajo de esto: ignorar (ambiente)
    TEMP_PERSON_MAX  = 40.0   # 26-40: verde (persona). >40: rojo (foco de calor)

    # Geometria del marker (en metros, frame map)
    DISTANCE_FROM_ROBOT = 2.0   # punto medio del rango utiil del MLX90640
    CIRCLE_RADIUS       = 2.0   # radio del circulo difuso

    # Throttling (evita inundar el mapa de markers basura)
    THROTTLE_TIME_S     = 3.0   # segundos minimos entre markers
    THROTTLE_DISTANCE_M = 0.5   # metros minimos entre markers consecutivos

    # Frames
    MAP_FRAME  = 'map'
    BASE_FRAME = 'base_link'

    def __init__(self):
        super().__init__('fire_detector_node')

        # TF: necesario para obtener la pose del robot en el frame map
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # Subscriber
        self.sub_temp = self.create_subscription(
            Float32, '/thermal/max_temp', self._on_max_temp, 10
        )

        # Publisher
        self.pub_markers = self.create_publisher(
            MarkerArray, '/fire_markers', 10
        )

        # Estado interno
        self.markers = []            # lista persistente acumulativa
        self.next_id = 0
        self.last_marker_time = None
        self.last_marker_pos  = None  # (x, y)

        self.get_logger().info(
            f'Fire detector iniciado. '
            f'Verde: {self.TEMP_MIN_DETECT}-{self.TEMP_PERSON_MAX}C, '
            f'Rojo: >{self.TEMP_PERSON_MAX}C. '
            f'Publicando en /fire_markers'
        )

    # ---------- TF ----------

    def _get_robot_pose(self):
        """Pose del robot en frame map. Devuelve (x, y, yaw) o None si TF no disponible."""
        try:
            t = self.tf_buffer.lookup_transform(
                self.MAP_FRAME, self.BASE_FRAME,
                rclpy.time.Time(),
                timeout=Duration(seconds=0.1)
            )
            x = t.transform.translation.x
            y = t.transform.translation.y
            q = t.transform.rotation
            yaw = math.atan2(
                2.0 * (q.w * q.z + q.x * q.y),
                1.0 - 2.0 * (q.y * q.y + q.z * q.z)
            )
            return x, y, yaw
        except Exception as e:
            self.get_logger().warn(
                f'TF {self.MAP_FRAME}->{self.BASE_FRAME} no disponible: {e}',
                throttle_duration_sec=5.0
            )
            return None

    # ---------- Throttling ----------

    def _should_create_marker(self, x, y):
        """True si el marker se debe crear, False si throttling lo bloquea."""
        now = self.get_clock().now()
        # Throttling temporal
        if self.last_marker_time is not None:
            elapsed_s = (now - self.last_marker_time).nanoseconds / 1e9
            if elapsed_s < self.THROTTLE_TIME_S:
                return False
        # Throttling espacial
        if self.last_marker_pos is not None:
            dx = x - self.last_marker_pos[0]
            dy = y - self.last_marker_pos[1]
            if math.hypot(dx, dy) < self.THROTTLE_DISTANCE_M:
                return False
        return True

    # ---------- Marker creation ----------

    def _create_marker(self, x, y, color, temp_c):
        """Cilindro plano (apariencia de circulo translucido top-down)."""
        m = Marker()
        m.header.stamp = self.get_clock().now().to_msg()
        m.header.frame_id = self.MAP_FRAME
        m.ns = 'fire_detector'
        m.id = self.next_id
        m.type = Marker.CYLINDER
        m.action = Marker.ADD

        # Posicion (centro)
        m.pose.position.x = x
        m.pose.position.y = y
        m.pose.position.z = 0.05  # apenas sobre el piso para visibilidad
        m.pose.orientation.w = 1.0

        # Escala: cilindro chato (radio horizontal, alto pequeno)
        m.scale.x = self.CIRCLE_RADIUS * 2.0  # diametro
        m.scale.y = self.CIRCLE_RADIUS * 2.0  # diametro
        m.scale.z = 0.1                        # alto bajito

        m.color = color

        # Lifetime 0 = permanente
        m.lifetime = Duration(seconds=0).to_msg()

        # Texto debug (visible en algunos visualizadores al hover)
        m.text = f'{temp_c:.1f}C'

        self.next_id += 1
        return m

    # ---------- Callback principal ----------

    def _on_max_temp(self, msg):
        temp = msg.data

        # Filtro ambiente
        if temp < self.TEMP_MIN_DETECT:
            return

        # Decidir color
        if temp <= self.TEMP_PERSON_MAX:
            color = ColorRGBA(r=0.0, g=0.85, b=0.0, a=0.3)   # verde translucido
            categoria = 'persona'
        else:
            color = ColorRGBA(r=0.95, g=0.1, b=0.05, a=0.3)  # rojo translucido
            categoria = 'foco'

        # Pose del robot
        pose = self._get_robot_pose()
        if pose is None:
            return
        rx, ry, ryaw = pose

        # Centro del circulo: 3.5m enfrente del robot en direccion de su yaw
        cx = rx + self.DISTANCE_FROM_ROBOT * math.cos(ryaw)
        cy = ry + self.DISTANCE_FROM_ROBOT * math.sin(ryaw)

        # Throttling
        if not self._should_create_marker(cx, cy):
            return

        # Crear marker y agregarlo a la lista permanente
        marker = self._create_marker(cx, cy, color, temp)
        self.markers.append(marker)
        self.last_marker_time = self.get_clock().now()
        self.last_marker_pos  = (cx, cy)

        # Publicar el array completo (todos los markers acumulados)
        arr = MarkerArray()
        arr.markers = self.markers
        self.pub_markers.publish(arr)

        self.get_logger().info(
            f'Deteccion {categoria}: T={temp:.1f}C en ({cx:.2f}, {cy:.2f}). '
            f'Total markers: {len(self.markers)}'
        )


def main():
    rclpy.init()
    node = FireDetectorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()