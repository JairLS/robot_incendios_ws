import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/jairls/robot_incendios_ws/install/rosmasterx3_sim'
