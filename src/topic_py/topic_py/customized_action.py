import math
import time
from robot_ros2_interfaces.msg import RobotActionParams


class CustomizedAction():

    def __init__(self, robot, id):
        self.robot = robot
        self.id = id
        self.dic_waittime = {
            "stand_up": 3,
            "lie_down": 3,
            "jump": 4,
            "front_jump": 4,
            "back_flip": 4,
            "shake_hand": 4,
            "two_leg_stand": 3
        }
        self._ba = BasicAction(robot)
        """动作基础包"""

    def customized_cmd_params(self, msg: RobotActionParams):
        """
            自定义有参数的机器指令。
            Args:
                msg(RobotActionParams): 指令名字与参数的消息接口
            RobotActionParams.msg:
                string action_name: 命令名称
                int32[] param_int: 整数参数
                float32[] param_float: 浮点数参数
                string[] param_string: 字符串参数
        """
        robot = self.robot
        self._ba.action_basic(msg)
        if self.id == "battle":
            BattleAction.action(robot, msg)
            return 0
        # 检查动作名字
        match msg.action_name:
            # 姿态控制(摆动)
            case "attitude_control":
                robot.attitudeControl(
                    msg.param_float[0], msg.param_float[1], msg.param_float[2], msg.param_float[3])
                time.sleep(4)
                robot.attitudeControl(0, 0, 0, 0)
            # 摇手
            case "shake_head":
                self.shake_head_smooth()
            # 姿态控制甩来甩去
            case "attitude_dance":
                self.head_circle_basic(radius=1.0)
            # 主方摇手，客方跳跃
            case "battle_shakeHand":
                robot.shakeHand()
                time.sleep(4)
                BasicAction.action_end(robot)
            # 客方摇手，主方起立
            case "battle_2_shakeHand":
                time.sleep(3)
                robot.twoLegStand(0.0, 0.0)
                time.sleep(3)
                robot.cancelTwoLegStand()
                BasicAction.action_end(robot)

            case "battle_jump":
                robot.jump()
                time.sleep(4)
                BasicAction.action_end(robot)
                pass

        return 0

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
            result = self.robot.attitudeControl(0, 0, speed, 0)
            if result != 0:
                print(f"姿态控制错误: 0x{result:x}")
                break

            time.sleep(0.02)  # 20ms

        # 停止
        self.robot.attitudeControl(0, 0, 0, 0)

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
                result = self.robot.attitudeControl(
                    roll_vel, pitch_vel, yaw_vel, height_vel)

                if result != 0:
                    print(f"姿态控制错误: 0x{result:x}")
                    break

                # 控制循环频率 ~50Hz
                time.sleep(0.02)

        except KeyboardInterrupt:
            print("用户中断")
        finally:
            self.robot.attitudeControl(0, 0, 0, 0)
            self._ba.action_end()
            print("头部转圈圈完成!")


class BasicAction():

    def __init__(self, robot):
        self.robot = robot
        pass

    def action_basic(self, msg: RobotActionParams):
        """
        动作基础包
        """
        match msg.action_name:
            case "stand_up":  # 站起
                self.robot.standUp()
                time.sleep(3)
            case "lie_down":  # 趴下
                self.robot.lieDown()
                time.sleep(3)
            case "jump":  # 跳跃
                self.robot.jump()
                time.sleep(4)
            case "front_jump":  # 前跳
                self.robot.frontJump()
                time.sleep(4)
            case "back_flip":  # 后空翻
                self.robot.backflip()
                time.sleep(4)
            case "shake_hand":  # 摇手
                self.robot.shakeHand()
                time.sleep(4)
            case "two_leg_stand":  # 双脚站立
                self.robot.twoLegStand(0.0, 0.0)
                time.sleep(3)
            case "two_leg_stand_c":  # 取消双脚站立
                self.robot.cancelTwoLegStand()
            case "attitude_control":  # 姿态控制(摆动)
                self._attitude_control(msg)

        if msg.action_name not in ["stand_up", "lie_down"]:
            self.action_end(self.robot)

    def _attitude_control(self, msg: RobotActionParams):
        """
        单方向姿态控制
        Args:
            msg(RobotActionParams): 动作参数
        Note:
            msg.param_float[0] = 0.5: 速度(-0.5rad/s~0.5rad/s)(-0.5m/s-0.5m/s)
            msg.param_float[1] = 1.0: 持续时间
            msg.param_string[0]: 姿态控制模式,"r" - 翻滚 "p" - 俯仰 "y" - 偏航 "h" - 高度
        example:
           示例："r+"为正方向，"r-"为负方向，"r"为默认正方向，可以不填"
           {"attitude_control", 0.5, 1.0, "r+"}
           {"attitude_control", 1.0, "r-"}
           {"attitude_control", "p+"}
        """
        speed = 0.5
        """默认速度"""
        s = 1.0
        """默认持续时间"""
        param_float_len = len(msg.param_float)
        """参数长度"""
        if param_float_len == 1:
            s = msg.param_float[0]
        elif param_float_len == 2:
            speed = msg.param_float[0]
            s = msg.param_float[1]

        if len(msg.param_string) > 1 and msg.param_string[1] == "-":
            speed = -speed

        match msg.param_string[0]:
            # 翻滚
            case "r":
                self.robot.attitudeControl(speed, 0.0, 0.0, 0.0)
            # 俯仰
            case "p":
                self.robot.attitudeControl(0.0, speed, 0.0, 0.0)
            # 偏航
            case "y":
                self.robot.attitudeControl(0.0, 0.0, speed, 0.0)
            # 高度
            case "h":
                self.robot.attitudeControl(0.0, 0.0, 0.0, speed)
        time.sleep(s)
        self.robot.attitudeControl(0.0, 0.0, 0.0, 0.0)

    def _attitude_control_preset(self, msg: RobotActionParams):
        count = msg.param_int[0]
        speed = 0.5
        match msg.param_string[0]:
            case "down":
                self.robot.attitudeControl(0.0, 0.0, 0.0, speed)
                time.sleep(0.2)
                for _ in range(count-1):
                    speed = -speed
                    self.robot.attitudeControl(0.0, 0.0, 0.0, speed)
                    time.sleep(0.5)
                self.robot.attitudeControl(0.0, 0.0, 0.0, 0.0)
            case "shakeHand":
                self.robot.attitudeControl(0.0, 0.0, speed, 0.0)
                time.sleep(0.2)
                for _ in range(count-1):
                    speed = -speed
                    self.robot.attitudeControl(0.0, 0.0, speed, 0.0)
                    time.sleep(0.5)
                self.robot.attitudeControl(0.0, 0.0, 0.0, 0.0)
            case "a1":
                params = RobotActionParams()
                params.msg.param_float[0] = 0.5
                mode = ["p-", "y+", "p-", "y-"]
                for _ in range(count):
                    for i in mode:
                        i2 = [i]
                        params.msg.param_string = i2
                        self._attitude_control(params)
                self.robot.attitudeControl(0.0, 0.0, 0.0, 0.0)
            case "shakeHand_3/4":
                for _ in range(count):
                    self.robot.attitudeControl(0.0, 0.0, speed, 0.0)
                    time.sleep(0.2)
                    self.robot.attitudeControl(0.0, 0.0, 0.0, 0.0)
                    time.sleep(0.2)
                    speed = -speed
                self.robot.attitudeControl(0.0, 0.0, 0.0, 0.0)
            case "V-shaped":
                params = RobotActionParams()
                params.msg.param_float[0] = 0.5
                mode = ["y+", "p+", "y-", "h-"]
                for _ in range(count):
                    for i in mode:
                        i2 = [i]
                        params.msg.param_string = i2
                        self._attitude_control(params)
                self.robot.attitudeControl(0.0, 0.0, 0.0, 0.0)

    @staticmethod
    def action_end(robot):
        """
        动作结束后调用的函数
        Args:
            robot(HighLevel): 机器人对象
        """
        robot.standUp()
        time.sleep(0.2)
        return 0


class BattleAction():
    """
    斗舞动作包
    """

    # 斗舞动作
    @staticmethod
    def action(robot, msg: RobotActionParams):
        """
        接收并处理自定义指令参数的回调函数。
        Args:
            robot(HighLevel): 机器人对象
            msg(RobotActionParams): 指令名字与参数的消息接口
        """
        customizedAction = CustomizedAction(robot=robot)
        match msg.action_name:
            # 姿态控制(摆动)
            case "attitude_control":
                robot.app.attitudeControl(
                    msg.param_float[0], msg.param_float[1], msg.param_float[2], msg.param_float[3])
                time.sleep(4)
                robot.app.attitudeControl(0, 0, 0, 0)
            case "shake_hand":  # 摇手
                robot.app.shakeHand()
                time.sleep(4)
                BasicAction.action_end(robot)
            case "shake_head":
                customizedAction.shake_head_smooth()
            case "attitude_dance":
                # 姿态控制甩来甩去
                customizedAction.head_circle_basic(radius=-1.0)
            case "battle_shakeHand":
                # 主方摇手，客方跳跃
                time.sleep(3)
                robot.app.jump()
                time.sleep(4)
                BasicAction.action_end(robot)
            case "battle_2_shakeHand":
                # 客方摇手，主方起立
                robot.app.shakeHand()
                time.sleep(4)
                BasicAction.action_end(robot)
            case "battle_jump":
                time.sleep(2)
                robot.app.jump()
                time.sleep(4)
                BasicAction.action_end(robot)
