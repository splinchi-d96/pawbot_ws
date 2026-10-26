from abc import ABC, abstractmethod
from geometry_msgs.msg import Twist
from robot_ros2_interfaces.msg import RobotActionEnum
from robot_ros2_interfaces.msg import TwistTime
from robot_ros2_interfaces.msg import RobotActionParams
#from robot_ros2_interfaces.srv import RobotAction


class AbstractGroupControlNode(ABC):
    """
    群控节点抽象类
    """

    @property
    @abstractmethod
    def linear_speed(self) -> float:
        """
        获取机器人线速度
        Returns:
            float: 机器人线速度(m/s)
        Note:
            线速度最好在0.2m/s或以上
        """
        pass

    @property
    @abstractmethod
    def angular_speed(self) -> float:
        """
        获取机器人角速度
        Returns:
            float: 机器人角速度(rad/s)
        """
        pass

    @property
    def is_mode_attitude_control(self) -> bool:
        """
        获取机器人是否启动姿态控制模式
        Returns:
            bool: True(已启动) False(未启动)
        """
        pass

    @abstractmethod
    def send_command_group(self, msg_value: RobotActionEnum.value) -> None:
        """
        发布命令话题（未完善）
        Args:
            msg_value(RobotAction.value): 命令值
        Note:
            参数直接填入RobotAction内置的枚举名就行了,当作枚举用,发送的值参考RobotAction枚举,
        example:
            self.send_command_group(RobotAction.STAND_UP)
            self.send_command_group(RobotAction.EXIT)
            self.send_command_group(RobotAction.JUMP)
        publish:
            RobotAction()
        """
        pass

    @abstractmethod
    def commandWithParameters(self, key: str, value: list) -> None:
        """
        发布带参命令话题
        Args:
            key(str): 命令名称
            value(list): 参数列表
        Note:
            建议使用RobotActionParams接口发送带参命令
        RobotActionParams.msg:
            string action_name: 命令名称
            int32[] param_int: 整数参数
            float32[] param_float: 浮点数参数
            string[] param_string: 字符串参数
        publish:
            RobotActionParams()
        """
        pass

    @abstractmethod
    def publisher_twist(self, msg: Twist) -> None:
        """
        发布速度话题
        Args:
            msg(Twist): 机器人线速度与角速度(m/s, rad/s)
        Twist.msg:
            float32 linear.x
            float32 linear.y
            float32 linear.z
            float32 angular.x
            float32 angular.y
            float32 angular.z
        publish:
            Twist()
        """
        pass

    @abstractmethod
    def quit(self) -> None:
        """
        退出程序
        Returns:
            None
        Note:
            函数体一定要有趴下指令的代码(发送RobotAction.EXIT)，不然可能会损害设备
        example:
            self.send_command_group(RobotAction.EXIT)
            self.destroy_node()
        """
        pass
