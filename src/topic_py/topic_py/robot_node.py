#!/usr/bin/env python3
"""
智元机器狗ROS2主控节点
功能：订阅运动指令，发布机器狗状态，并控制底层硬件。
"""
import math
import os
import platform
from re import match
import sys
import time

import rclpy
from rclpy.node import Node
from ament_index_python.packages import get_package_share_directory
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from std_msgs.msg import Header
from sensor_msgs.msg import Imu, BatteryState, JointState
from robot_ros2_interfaces.msg import RobotActionEnum  # 功能枚举接口
from robot_ros2_interfaces.msg import RobotActionParams
from robot_ros2_interfaces.msg import TwistTime
from .customized_action import CustomizedAction

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


class RobotNode(Node):
    """
    智元机器狗ROS2节点类
    """

    def __init__(self, name: str):
        super().__init__(name)
        self.get_logger().info("智元机器狗ROS2节点已启动")
        # 参数声明（例如，配置机器狗的通信端口）
        self.declare_parameter('command_frequency', 50.0)  # 控制指令频率
        self.declare_parameter('client_ip', '192.168.234.9')  # 本机IP
        self.declare_parameter('robot_ip', '192.168.234.1')  # 机器狗IP
        self.declare_parameter('port', 43988)  # 端口号

        self.vx = 0.0
        """前向速度"""
        self.vy = 0.0
        """侧向速度"""
        self.yaw_rate = 0.0
        """绕Z轴角速度"""
        self._is_mode_attitude_control = False
        """姿态控制模式"""
        self.motion_state = String()
        """机器狗运动状态"""

        self.app = mc_sdk_zsl_1_py.HighLevel()
        self.app.initRobot(
            self.get_parameter('client_ip').value,
            self.get_parameter('port').value,
            self.get_parameter('robot_ip').value
        )
        # 检查是否连接成功，连接不成功则退出程序
        self.app.standUp()
        time.sleep(3)
        if (str(self.app.move(0, 0, 0)) == "0"):
            self.get_logger().info("智元机器狗节点已启动，等待指令...")
            self.app.lieDown()
            time.sleep(2)
            self.app.passive()
        else:
            self.get_logger().error("机器狗启动失败")
            self.destroy_node()
            raise Exception("启动失败")

        self._customized_cmd_class = CustomizedAction(robot=self.app)

        self.subs_cmd = self.create_subscription(
            RobotActionEnum, '/group_control_cmd',  self.cmd_callback, 10)
        """指令订阅者"""
        self.subs_twist = self.create_subscription(
            Twist, '/group_control_vel',  self.twist_callback, 10)
        """速度订阅者"""
        self.subs_attitude_control_twist = self.create_subscription(
            Twist, '/group_control_cmd_params',  self.attitude_control_twist_callback, 10)
        """姿态控制订阅者"""

        self.subs_twist_time = self.create_subscription(
            TwistTime, '/group_control_vel_time',  self.twist_time_callback, 10)
        """速度订阅者(指定时间)"""
        self.subs_cmd_params = self.create_subscription(
            RobotActionParams, '/group_control_cmd_params',  self.cmd_params_callback, 10)
        """带参指令订阅者"""
        self._publisher_motion_state = self.create_publisher(
            String, '/motion_state', 10)
        """运动状态发布者"""

        # 创建发布者：发布机器狗的各种状态信息
        # 发布自定义的机器狗整体状态（需自定义消息）
        # self.dog_status_publisher = self.create_publisher(DogStatus, 'dog_status', 10)

        # 控制定时器：定期发送指令到底层硬件
        # self.timer = self.create_timer(
        #     1.0 / self.command_freq, self.timer_callback)

        # 初始化与底层硬件的连接（此处需要根据机器狗的实际接口实现）
        # self.init_hardware_connection()

    def init_hardware_connection(self):
        """
        初始化与机器狗底层的硬件连接。
        具体实现取决于机器狗提供的接口（如UART、CAN、SDK等）。
        """
        pass
        self.get_logger().info(
            f"尝试使用 {self.hardware_iface} 在 {self.port_name} 初始化硬件连接")
        try:
            # 示例：使用串口连接
            # self.serial_connection = serial.Serial(self.port_name, baudrate=115200, timeout=1)
            # 或者使用机器狗官方的SDK
            # self.dog_controller = DogController(ip_address="192.168.1.10", port=5000)
            self.get_logger().info("硬件连接初始化成功")
        except Exception as e:
            self.get_logger().error(f"硬件连接失败: {str(e)}")

    def cmd_callback(self, msg: RobotActionEnum):
        """
        接收并处理指令的回调函数。
        Args:
            msg(RobotActionEnum): 机器狗指令消息
        """
        current_cmd = msg.value
        match current_cmd:
            case RobotActionEnum.STAND_UP:  # 站起
                self.app.standUp()
                time.sleep(3)
            case RobotActionEnum.LIE_DOWN:  # 趴下
                self.app.lieDown()
                time.sleep(3)
            case RobotActionEnum.JUMP:  # 跳跃
                self.app.jump()
                time.sleep(4)
            case RobotActionEnum.FRONT_JUMP:  # 前跳
                self.app.frontJump()
                time.sleep(4)
            case RobotActionEnum.BACK_FLIP:  # 后空翻
                self.app.backflip()
                time.sleep(4)
            case RobotActionEnum.SHAKE_HAND:  # 摇手
                self.app.shakeHand()
                time.sleep(4)
            case RobotActionEnum.TWO_LEG_STAND:  # 双脚站立
                self.app.twoLegStand(0.0, 0.0)
                time.sleep(3)
            case RobotActionEnum.TWO_LEG_STAND_C:  # 取消双脚站立
                self.app.cancelTwoLegStand()
            case RobotActionEnum.ATTITUDE_CONTROL:  # 姿态控制(摆动)
                self.app.attitudeControl(0.1, 0.1, 0.1, 0.1)
                time.sleep(2)
            case RobotActionEnum.RESET:  # 复位
                yawRad = self.truncate_decimal(self.app.getRPY()[2])
                # 复位
                while yawRad > 0.1 or yawRad < -0.1:
                    self.get_logger().info(f"位置: 偏航角 {yawRad}")
                    yawRad = self.truncate_decimal(self.app.getRPY()[2])
                    self.app.move(0, 0, 0.2)
                self.app.move(0, 0, 0)

                for i in range(5):
                    x = self.truncate_decimal(self.app.getPosition()[0])
                    y = self.truncate_decimal(self.app.getPosition()[1])
                    self.get_logger().info(f"位置: x={x}, y={y}")
                    time.sleep(2)
                    if x > 0.2:
                        self.app.move(-0.2, 0, 0)
                        time.sleep(2)
                        self.app.move(0, 0, 0)
                        self.get_logger().info("正在向后走")
                    elif x < -0.2:
                        self.app.move(0.2, 0, 0)
                        time.sleep(2)
                        self.app.move(0, 0, 0)
                        self.get_logger().info("正在向前走")
                    elif y > 0.2:
                        self.app.move(0, -0.2, 0)
                        time.sleep(2)
                        self.app.move(0, 0, 0)
                        self.get_logger().info("正在向右走")
                    elif y < -0.2:
                        self.app.move(0, 0.2, 0)
                        time.sleep(2)
                        self.app.move(0, 0, 0)
                        self.get_logger().info("正在向左走")
                    else:
                        break
                self.app.move(0, 0, 0)
            case RobotActionEnum.EXIT:  # 退出
                self.app.lieDown()
                time.sleep(3)
                self.destroy_node()
                raise KeyboardInterrupt

        if msg.value not in [RobotActionEnum.EXIT, RobotActionEnum.STAND_UP, RobotActionEnum.LIE_DOWN]:
            self.action_end()

        # 临时日志输出，用于调试
        self.get_logger().debug(
            f'收到指令: 正在执行 {msg.value} ')

    def cmd_params_callback(self, msg: RobotActionParams):
        """
        接收并处理自定义指令参数的回调函数。
        """
        self._customized_cmd_class.customized_cmd_params(msg)
        self.motion_state.data = "stand_up"
        self._publisher_motion_state.publish(self.motion_state)

    def twist_callback(self, msg: Twist):
        """
        接收并处理Twist消息的回调函数。处理速度控制。
        Args:
            msg(Twist): 机器狗速度消息
        """
        self.vx = msg.linear.x
        self.vy = msg.linear.y
        self.yaw_rate = msg.angular.z
        self.app.move(self.vx, self.vy, self.yaw_rate)

    def attitude_control_twist_callback(self, msg: Twist):
        """
        接收并处理姿态控制Twist消息的回调函数。处理姿态控制。
        Args:
            msg(Twist): 姿态控制消息
        """
        self.app.attitudeControl(
            msg.angular.x, msg.angular.y, msg.angular.z, msg.linear.z)

    def twist_time_callback(self, msg: TwistTime):
        """
        接收并处理TwistTime消息的回调函数。处理指定时间内的速度控制。
        Args:
            msg(TwistTime): 机器狗速度消息和持续时间
        """
        twist = msg.twist
        self.vx = twist.linear.x
        self.vy = twist.linear.y
        self.yaw_rate = twist.angular.z
        self.app.move(self.vx, self.vy, self.yaw_rate)
        time.sleep(msg.time)
        self.app.move(0.0, 0.0, 0.0)
        self.action_end()

    def action_end(self):
        """
        动作结束后调用的函数
        """
        self.app.standUp()
        time.sleep(0.2)

    def truncate_decimal(self, num: float, n: int) -> float:
        """将数字截断到小数点后n位（四舍五不入）
        Args:
            num(float): 待截断的数字
            n(int): 小数点后位数
        """
        factor = 10 ** n
        if num >= 0:
            return math.floor(num * factor) / factor
        else:
            return math.ceil(num * factor) / factor

    def timer_callback(self):
        """
        定时器回调函数，用于周期性地：
        1. 发送控制指令给机器狗。
        2. 读取并发布机器狗的状态传感器数据。
        """
        # 1. 发送控制指令
        self.send_movement_command()

        # 2. 发布传感器数据
        self.publish_sensor_data()

    def send_movement_command(self):
        """
        将当前的速度指令(self.current_cmd_vel)通过硬件接口发送给机器狗。
        """
        # 这里需要实现将ROS2的Twist消息转换为机器狗底层控制器能理解的协议
        # 例如，转换并通过串口发送
        # command_packet = self.format_command_packet(self.current_cmd_vel)
        # if self.serial_connection and self.serial_connection.is_open:
        #     self.serial_connection.write(command_packet)
        pass

    def publish_sensor_data(self):
        """
        从机器狗读取传感器数据，并发布到ROS2话题上。
        """
        # # 示例：发布电池状态
        # battery_msg = BatteryState()
        # battery_msg.header = Header()
        # battery_msg.header.stamp = self.get_clock().now().to_msg()
        # battery_msg.voltage = 12.6  # 应从硬件读取真实值
        # battery_msg.percentage = 0.85  # 应从硬件读取真实值
        # self.battery_publisher.publish(battery_msg)

        # # 示例：发布IMU数据 (需要真实数据填充)
        # imu_msg = Imu()
        # imu_msg.header = Header()
        # imu_msg.header.stamp = self.get_clock().now().to_msg()
        # # imu_msg.orientation, imu_msg.angular_velocity, imu_msg.linear_acceleration 需要从传感器读取
        # self.imu_publisher.publish(imu_msg)

        # 发布自定义的机器狗状态消息 (需要自定义DogStatus.msg)
        # dog_status_msg = DogStatus()
        # dog_status_msg.mode = "running"
        # dog_status_msg.foot_force = [10.2, 11.5, 9.8, 10.9]
        # self.dog_status_publisher.publish(dog_status_msg)


def main(args=None):
    rclpy.init(args=args)
    try:
        node = RobotNode("node_01")
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
