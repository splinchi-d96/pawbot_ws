import time

import pygame
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from robot_ros2_interfaces.msg import RobotActionEnum
from robot_ros2_interfaces.msg import TwistTime
from robot_ros2_interfaces.msg import RobotActionParams
# from robot_ros2_interfaces.srv import RobotAction
from .abc.abc_group_control_node import AbstractGroupControlNode
import tkinter as tk
from tkinter import filedialog, scrolledtext, messagebox
import threading
import json

dir_robotAction = {
    "exit": RobotActionEnum.EXIT,
    "stand_up": RobotActionEnum.STAND_UP,
    "lie_down": RobotActionEnum.LIE_DOWN,
    "jump": RobotActionEnum.JUMP,
    "front_jump": RobotActionEnum.FRONT_JUMP,
    "back_flip": RobotActionEnum.BACK_FLIP,
    "shake_hand": RobotActionEnum.SHAKE_HAND,
    "attitude_control": RobotActionEnum.ATTITUDE_CONTROL,
    "reset": RobotActionEnum.RESET,
    "two_leg_stand": RobotActionEnum.TWO_LEG_STAND,
    "two_leg_stand_c": RobotActionEnum.TWO_LEG_STAND_C
}


class GroupControlNode(Node, AbstractGroupControlNode):
    def __init__(self, name: str):
        """
        群控节点类
        Args:
            name(str): 节点名称
        """
        super().__init__(name)
        self.get_logger().info("群控节点 %s 已启动!" % name)

        self._linear_speed = 0.5
        self._angular_speed = 1.0
        self.idle_count = 2

        self._is_mode_attitude_control = False
        """姿态控制模式"""

        # 群控发布者
        self._publisher_action = self.create_publisher(
            RobotActionEnum, "/group_control_cmd", 10)
        """指令发布者"""

        self._publisher_twist_time = self.create_publisher(
            TwistTime, "/group_control_vel_time", 10)
        """指定时间速度发布者"""

        self._publisher_twist = self.create_publisher(
            Twist, "/group_control_vel", 10)
        """速度发布者"""

        self._publisher_action_params = self.create_publisher(
            RobotActionParams, "/group_control_cmd_params", 10)
        """指令发布者（有参数）"""

        self._subscription_motion_state = self.create_subscription(
            String, '/motion_state', self.motion_state_callback, 10)

        # self.subs_thread = threading.Thread(target=self.subs_motion_state)
        # self.subs_thread.daemon = True
        # self.subs_thread.start()

        # 创建订阅者：接收odom
        # self.create_subscription(Odometry, "/dog1/odom", self.dog1_odom_cb, 10)

    @property
    def linear_speed(self) -> float:
        return self._linear_speed

    @property
    def angular_speed(self) -> float:
        return self._angular_speed

    @property
    def motion_state(self) -> str:
        return self._motion_state

    @property
    def is_mode_attitude_control(self) -> bool:
        return self._is_mode_attitude_control

    def dog1_odom_cb(self, msg):
        pass
        # 处理dog1的里程计数据（如打印位置）
        self.get_logger().info(
            f"Dog1 Position: x={msg.pose.pose.position.x:.2f}")

    def subs_motion_state(self):
        self._subscription_motion_state = self.create_subscription(
            String, '/motion_state', self.motion_state_callback, 10)

    def motion_state_callback(self, msg: String) -> None:
        if msg.data == "stand_up":
            self.idle_count += 1

    def send_command_group(self, msg_value: RobotActionEnum.value) -> None:
        msg = RobotActionEnum()
        msg.value = msg_value
        self._publisher_action.publish(msg)

    def publisher_twist(self, msg: Twist) -> None:
        self._publisher_twist.publish(msg)

    def commandWithParameters(self, key: str, value) -> None:
        while self.idle_count < 2:
            self.get_logger().info(f"正在等待中{self.idle_count}")
            time.sleep(2)
        # 等待wait
        if key == "wait":
            time.sleep(value[0])
        elif key == "move":
            twist = Twist()
            twistTime = TwistTime()

            twist.linear.x, twist.linear.y, twist.angular.z = value[0], value[1], value[2]
            twistTime.twist, twistTime.time = twist, value[3]

            self._publisher_twist_time.publish(twistTime)

            time.sleep(value[3] + 2)
        elif isinstance(key, str):
            msg = RobotActionParams()
            msg.action_name = key
            # 添加参数进各个类型
            p_int, p_float, p_string = [], [], []
            for param in value:
                if isinstance(param, int):
                    p_int.append(param)
                elif isinstance(param, float):
                    p_float.append(param)
                elif isinstance(param, str):
                    p_string.append(param)
            msg.param_int = p_int
            msg.param_float = p_float
            msg.param_string = p_string
            self._publisher_action_params.publish(msg)
            self.idle_count = 0

    def quit(self) -> None:
        self.send_command_group(RobotActionEnum.EXIT)
        self.get_logger().info("按q退出,节点关闭中...")
        self.destroy_node()
        rclpy.shutdown()  # 关闭ROS2


class GroupControlGui():

    def __init__(self, node: AbstractGroupControlNode):
        """群控界面GUI类
        Args:
            node (Node): 群控节点
        """
        self.node = node
        """群控节点"""
        # 启动 GUI 线程
        self.gui_thread = threading.Thread(target=self.create_gui)
        self.gui_thread.daemon = True
        self.gui_thread.start()

    def create_gui(self):
        """创建控制GUI"""
        self.root = tk.Tk()
        pygame.init()
        self.root.title("机器狗遥控器")
        self.root.geometry("600x600")

        title_label = tk.Label(self.root, text="机器人控制说明")
        title_label.pack(fill='x', pady=(0, 10))
        label = tk.Label(
            self.root, text="""空格起立,WASD上下左右移动,←→左右转
        Q退出,O复位
        y跳,u前跳,i后空翻,o不要按
        h摇手,j双脚站立,k取消站立,l姿态控制""")
        label.pack()

        # 控制按钮
        frame = tk.Frame(self.root)
        frame.pack(expand=True)

        # 单个文件选择
        tk.Button(frame, text="选择单个文件", command=self.select_single_file).grid(
            row=0, column=0, padx=5, pady=5, sticky='w')
        self.entry_path = tk.Entry(frame, width=50)
        self.entry_path.grid(row=0, column=1, padx=5, pady=5)

        # 打开音乐文件选择
        tk.Button(frame, text="选择音乐文件", command=self.select_music_file).grid(
            row=1, column=0, padx=5, pady=5, sticky='w')
        self.music_path = tk.Entry(frame, width=50)
        self.music_path.grid(row=1, column=1, padx=5, pady=5)

        # 打开并读取文件
        tk.Button(frame, text="启动！", command=self.file_start).grid(
            row=2, column=0, padx=5, pady=5, sticky='w')

        # 退出按钮
        btn_quit = tk.Button(self.root, text="退出 Q", command=self.quit)
        btn_quit.pack(pady=10)

        # 用于显示多行结果的文本区域
        self.text_area = scrolledtext.ScrolledText(
            self.root, width=70, height=15)
        self.text_area.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)

        # 绑定键盘事件
        self.pending_releases = {}
        """键盘释放事件"""
        self.root.bind('<KeyPress>', self._on_key_press)
        self.root.bind('<KeyRelease>', self._on_key_release)
        self.root.focus_set()

        # 按键状态跟踪
        self.key_states = {'w': False, 'a': False, 's': False,
                           'd': False, 'left': False, 'right': False}

        # ATTITUDE_CONTROL
        self.attitude_control_mode = False

        self.root.mainloop()

    def _on_key_press(self, event: tk.Event):
        """键盘按下事件"""
        key = event.keysym.lower()
        if key == 'plus':
            self.attitude_control_mode = not self.attitude_control_mode
            add_key_dic = {
                'up': False, 'down': False, 'j': False, 'k': False, 'n': False, 'm': False
            }
            if self.attitude_control_mode:
                self.key_states.update(add_key_dic)
            elif not self.attitude_control_mode:
                for i in add_key_dic:
                    del self.key_states[i]
            self.node.get_logger().info(
                f"姿态控制模式: {self.attitude_control_mode}")
        elif key in self.key_states:
            self.key_states[key] = True
            if key in self.pending_releases:
                self.root.after_cancel(self.pending_releases[key])
                del self.pending_releases[key]
            self._on_key_update()
        else:
            # 机器人动作字典
            actionKey_dict = {
                'space': [RobotActionEnum.STAND_UP, "起立"],
                'h': [RobotActionEnum.SHAKE_HAND, "摇手"],
                'y': [RobotActionEnum.JUMP, "跳"],
                'u': [RobotActionEnum.FRONT_JUMP, "前跳"],
                'i': [RobotActionEnum.BACK_FLIP, "后空翻"],
                'j': [RobotActionEnum.TWO_LEG_STAND, "双腿站立"],
                'k': [RobotActionEnum.TWO_LEG_STAND_C, "取消双腿站立"],
                'l': [RobotActionEnum.ATTITUDE_CONTROL, "姿态控制"],
                # 'o': [RobotActionEnum.RESET, "复位"]
            }
            if key in actionKey_dict:
                self.node.send_command_group(actionKey_dict[key][0])
                self.node.get_logger().info("已发布: "+actionKey_dict[key][1])

    def _on_key_release(self, event: tk.Event):
        """键盘释放事件"""
        key = event.keysym.lower()
        timer_id = self.root.after(50, self._on_key_release_callback, key)
        self.pending_releases[key] = timer_id

    def _on_key_release_callback(self, key: str):
        if key in self.key_states:
            del self.pending_releases[key]
            self.key_states[key] = False
            self.node.get_logger().info("已发布: 松开%s键" % key)
            self._on_key_update()
        elif key == 'q':
            self.node.quit()

    def _on_key_update(self):
        """按键状态更新命令"""
        twist = Twist()
        # 线性速度
        if self.key_states['w'] and not self.key_states['s']:
            twist.linear.x = self.node.linear_speed
            self.node.get_logger().info("已发布: 前进")
        elif self.key_states['s'] and not self.key_states['w']:
            twist.linear.x = -self.node.linear_speed
            self.node.get_logger().info("已发布: 后退")
        if self.key_states['a'] and not self.key_states['d']:
            twist.linear.y = self.node.linear_speed
            self.node.get_logger().info("已发布: 向左")
        elif self.key_states['d'] and not self.key_states['a']:
            twist.linear.y = -self.node.linear_speed
            self.node.get_logger().info("已发布: 向右")
        # 角速度
        if self.attitude_control_mode == True:
            if self.key_states['up'] and not self.key_states['down']:
                twist.angular.y = self.node.angular_speed
            elif self.key_states['down'] and not self.key_states['up']:
                twist.angular.y = -self.node.angular_speed
            if self.key_states['left'] and not self.key_states['right']:
                twist.angular.z = self.node.angular_speed
            elif self.key_states['right'] and not self.key_states['left']:
                twist.angular.z = -self.node.angular_speed
        else:
            if self.key_states['left'] and not self.key_states['right']:
                twist.angular.z = self.node.angular_speed
                self.node.get_logger().info("已发布: 左转")
            elif self.key_states['right'] and not self.key_states['left']:
                twist.angular.z = -self.node.angular_speed
                self.node.get_logger().info("已发布: 右转")
        self.node.publisher_twist(twist)

    def select_single_file(self):
        """选择单个文件，并将路径显示在输入框内"""
        file_path = filedialog.askopenfilename(
            title="选择单个文件",
            filetypes=[("json文件", "*.json"),
                       (".yaml文件", "*.yaml"), ("所有文件", "*.*")]
        )
        self.entry_path.delete(0, tk.END)
        self.entry_path.insert(0, file_path)

    def select_music_file(self):
        """选择单个音乐文件，并将路径显示在输入框内"""
        file_path = filedialog.askopenfilename(
            title="选择音乐文件",
            filetypes=[("音频文件", "*.mp3 *.wav *.ogg"), ("所有文件", "*.*")]
        )
        self.music_path.delete(0, tk.END)
        self.music_path.insert(0, file_path)

    def file_start(self):
        """打开文件并读取其内容"""
        file_path = self.entry_path.get()
        music_path = self.music_path.get()

        if file_path:
            # 音乐
            if music_path:
                try:
                    pygame.mixer.music.load(music_path)
                    pygame.mixer.music.play()
                except Exception as e:
                    messagebox.showerror("错误", f"播放时出错: {e}")
            # json
            try:
                with open(file_path, 'r', encoding='utf-8') as file:
                    data = json.load(file)
                self.text_area.delete(1.0, tk.END)
                self.text_area.insert(tk.END, f"成功加载JSON文件: {file_path}\n\n")
                self.show_structure(data)
                self._traverse_json(data["actions"])
            except json.JSONDecodeError as e:
                messagebox.showerror("错误", f"JSON格式错误: {e}")
            except Exception as e:
                messagebox.showerror("错误", f"读取文件时出错: {e}")

    def show_structure(self, data):
        """显示JSON数据结构"""
        if data is None:
            return

        self.text_area.insert(tk.END, "数据结构:\n")
        self.text_area.insert(tk.END, f"数据类型: {type(data).__name__}\n")

        if isinstance(data, dict):
            self.text_area.insert(tk.END, f"键数量: {len(data)}\n")
            self.text_area.insert(tk.END, f"所有键: {list(data.keys())}\n")
        elif isinstance(data, list):
            self.text_area.insert(tk.END, f"元素数量: {len(data)}\n")

        self.text_area.insert(tk.END, "\n" + "="*50 + "\n")

        self.text_area.update_idletasks()

    def _traverse_json(self, obj, level=0):
        """递归遍历JSON对象"""
        indent = "  " * level
        if isinstance(obj, list):
            for i, item in enumerate(obj):
                self.text_area.insert(tk.END, f"{indent}[{i}]: ")
                for pose in item["target_pose"]:
                    if isinstance(pose, dict):
                        for key, value in pose.items():
                            self.text_area.insert(
                                tk.END, f"{indent}{key}: {value}\n")
                            self.node.commandWithParameters(key, value)
                    else:
                        if pose in dir_robotAction:
                            self.node.send_command_group(dir_robotAction[pose])
                            time.sleep(4)
        time.sleep(4)
        pygame.mixer.music.fadeout(3000)

    def quit(self):
        """退出程序"""
        self.node.quit()
        self.root.destroy()


def main(args=None):
    rclpy.init(args=args)

    try:
        node = GroupControlNode("group_control_node")
        gui = GroupControlGui(node)
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        print(f"Node error: {e}")
    finally:
        # 确保资源被正确清理
        gui.root.quit()
        node.quit()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()


def open_json_file():
    file_path = filedialog.askopenfilename(
        title="选择JSON文件",
        filetypes=[("JSON文件", "*.json"), ("所有文件", "*.*")]
    )

    if file_path:
        try:
            # 打开文件并解析JSON
            with open(file_path, 'r', encoding='utf-8') as file:
                data = json.load(file)
                display_json_content(data)
        except Exception as e:
            print(f"读取文件时出错: {e}")


def display_json_content(data):
    """显示JSON内容"""
    print("JSON数据:", data)
