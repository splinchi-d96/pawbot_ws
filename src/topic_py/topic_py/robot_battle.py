"""
智元机器狗ROS2主控节点
功能：订阅运动指令，发布机器狗状态，并控制底层硬件。
"""
import math
import os
import platform
import random
import sys
import time

import rclpy
from rclpy.node import Node
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import Twist
from std_msgs.msg import Header
from sensor_msgs.msg import Imu, BatteryState, JointState
from robot_ros2_interfaces.msg import RobotActionEnum  # 功能枚举接口
from robot_ros2_interfaces.msg import RobotActionParams
from robot_ros2_interfaces.msg import TwistTime
from .robot_node import RobotNode

# 设置智元sdk库路径
# 获取功能包的share目录路径
pkg_share = get_package_share_directory('topic_py')
# 获取本机的架构
arch = platform.machine().replace('amd64', 'x86_64').replace('arm64', 'aarch64')
# 拼接资源文件路径
lib_path = os.path.abspath(os.path.join(pkg_share, 'lib/zsl-1', arch))
print(lib_path)
sys.path.insert(0, lib_path)

# fmt: off
import mc_sdk_zsl_1_py # pyright: ignore[reportMissingImports]
# fmt: on


class RobotNodeBattle(RobotNode):
    """
    智元机器狗ROS2节点类
    """

    def cmd_params_callback(self, msg: RobotActionParams):
        """
        接收并处理自定义指令参数的回调函数。
        """
        if msg.action_name == "attitude_control":  # 姿态控制(摆动)
            self.app.attitudeControl(
                msg.param_float[0], msg.param_float[1], msg.param_float[2], msg.param_float[3])
            time.sleep(4)
            self.app.attitudeControl(0, 0, 0, 0)
        elif msg.action_name == "shake_hand": # 摇手
            self.app.shakeHand()
            time.sleep(4)
            self.action_end()
        elif msg.action_name == "shake_head":
            self.shake_head_smooth()
        elif msg.action_name == "attitude_dance":
            # 姿态控制甩来甩去
            self.head_circle_basic(radius=-1.0)
        elif msg.action_name == "battle_shakeHand":
            # 主方摇手，客方跳跃
            time.sleep(3)
            self.app.jump()
            time.sleep(4)
            self.action_end()
        elif msg.action_name == "battle_2_shakeHand":
            # 客方摇手，主方起立
            self.app.shakeHand()
            time.sleep(4)
            self.action_end()
        elif msg.action_name == "battle_jump":
            time.sleep(2)
            self.app.jump()
            time.sleep(4)
            self.action_end()
        self.motion_state.data = "stand_up"
        self._publisher_motion_state.publish(self.motion_state)

    def twist_callback(self, msg: Twist):
        """
        接收并处理Twist消息的回调函数。处理速度控制。
        Args:
            msg(Twist): 机器狗速度消息
        """
        self.vx = msg.linear.x
        self.vy = -msg.linear.y
        self.yaw_rate = -msg.angular.z
        self.app.move(self.vx, self.vy, self.yaw_rate)

    def twist_time_callback(self, msg: TwistTime):
        """
        接收并处理TwistTime消息的回调函数。处理指定时间内的速度控制。
        Args:
            msg(TwistTime): 机器狗速度消息和持续时间
        """
        twist = msg.twist
        self.vx = twist.linear.x
        self.vy = -twist.linear.y
        self.yaw_rate = -twist.angular.z
        self.app.move(self.vx, self.vy, self.yaw_rate)
        time.sleep(msg.time)
        self.app.move(0.0, 0.0, 0.0)
        self.action_end()

    def shake_head_smooth(self, duration=10.0, max_speed=0.4):
        """
        正弦波摇头动作
        """
        self.is_running = True
        start_time = time.time()

        while self.is_running:
            elapsed = time.time() - start_time
            if elapsed >= duration:
                break

            progress = elapsed / duration
            # 正弦波控制速度
            speed = max_speed * math.sin(2 * math.pi * progress * 2)

            # 执行姿态控制
            result = self.app.attitudeControl(0, 0, speed, 0)
            if result != 0:
                print(f"姿态控制错误: 0x{result:x}")
                break

            time.sleep(0.02)  # 20ms

        # 停止
        self.app.attitudeControl(0, 0, 0, 0)

    def head_circle_basic(self, duration=5.0, circle_speed=1.0, radius=0.5):
        """
        基础头部转圈动作
        duration: 动作持续时间(秒)
        circle_speed: 转圈速度(圈/秒)
        radius: 头部运动半径(幅度)
        """

        self.is_running = True
        start_time = time.time()

        try:
            while self.is_running and (time.time() - start_time) < duration:
                elapsed = time.time() - start_time

                # 计算当前角度 (弧度)
                angle = 2 * math.pi * circle_speed * elapsed

                # 使用正弦和余弦函数创建圆形运动
                # 偏航(Yaw) - 水平旋转
                yaw_vel = radius * math.sin(angle) * 0.3

                # 俯仰(Pitch) - 上下点头
                pitch_vel = radius * math.cos(angle) * 0.3

                # 横滚(Roll) - 左右倾斜，增加立体感
                roll_vel = radius * math.sin(angle + math.pi/4) * 0.2

                # 轻微的高度变化，增强动态效果
                height_vel = radius * math.sin(2 * angle) * 0.1

                # 执行姿态控制
                result = self.app.attitudeControl(
                    roll_vel, pitch_vel, yaw_vel, height_vel)

                if result != 0:
                    print(f"姿态控制错误: 0x{result:x}")
                    break

                # 控制循环频率 ~50Hz
                time.sleep(0.02)

        except KeyboardInterrupt:
            print("用户中断")
        finally:
            self.app.attitudeControl(0, 0, 0, 0)
            self.action_end()
            print("头部转圈圈完成!")


def main(args=None):
    rclpy.init(args=args)
    try:
        node = RobotNodeBattle("node_01")
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("节点被用户关闭。")
    except Exception as e:
        node.get_logger().info(f"节点运行时发生错误：{e}")
    finally:
        # 销毁节点并清理资源
        node.app.lieDown()
        time.sleep(3)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
