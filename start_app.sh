#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
INSTALL_DIR="$SCRIPT_DIR/install"

# 环境变量配置 setup.bash
source "$INSTALL_DIR/setup.bash"

# 启动程序，在此修改机器狗IP与端口
echo "正在启动程序..."
ros2 launch robot_startup example_action.launch.py \
  robot_configs:='[
  {"id":1,"ip":"192.168.1.116","port":10047},
  {"id":2,"ip":"192.168.1.110","port":10131}
  ]'