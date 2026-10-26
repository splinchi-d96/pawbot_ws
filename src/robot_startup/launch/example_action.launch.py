# 导入库
import socket
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

CLIENT_IP = "192.168.1.107"
robot_count = 2
"""本机IP"""


def generate_launch_description():
    """launch内容描述函数，由ros2 launch 扫描调用"""
    CLIENT_IP = get_local_ip()
    print(CLIENT_IP)
    robot_configs_arg = DeclareLaunchArgument(
        'robot_configs',
        default_value='[{"id":1,"ip":"192.168.1.101","port":8080},{"id":2,"ip":"192.168.1.102","port":8081}]',
        description='JSON格式的机器人配置'
    )
    node_control_1 = Node(
        package="topic_py",
        namespace="control",
        executable="group_control_node",
    )
    # 每个机器人初始化的IP和端口
    # robot_init = [
    #     {'robot_ip': '192.168.1.110', 'port': 10131},
    #     {'robot_ip': '192.168.1.106', 'port': 10168},
    #     {'robot_ip': '192.168.1.116', 'port': 10047}
    # ]

    def create_robot_nodes(context):
        import json
        configs_str = LaunchConfiguration('robot_configs').perform(context)
        robot_init = json.loads(configs_str)

        robot_nodes = [
            Node(
                package="topic_py",
                namespace=f"robot_dog_{robot_init[i]['id']}",
                executable="robot_battle" if robot_init[i]['id'] == 2 else "robot_node",
                name=f"robot_node_{robot_init[i]['id']}",  # 给节点起唯一名字
                parameters=[{
                    'client_ip': CLIENT_IP,
                    'robot_ip': robot_init[i]['ip'],
                    'port': robot_init[i]['port'],
                    'robot_id': robot_init[i]['id']  # 添加robot_id参数
                }],
            )
            for i in range(robot_count)
        ]
        return robot_nodes

    from launch.actions import OpaqueFunction
    robot_nodes = OpaqueFunction(function=create_robot_nodes)

    # 创建LaunchDescription对象launch_description,用于描述launch文件
    launch_description = LaunchDescription([
        robot_configs_arg,
        node_control_1,
        robot_nodes
    ])
    # 返回让ROS2根据launch描述执行节点
    return launch_description

def get_local_ip():
    """获取本机局域网 IP"""
    try:
        # 创建一个socket连接
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        # 不需要真正连接，所以使用一个不会响应的地址
        s.connect(('10.255.255.255', 1))  # Google 的公共 DNS
        ip = s.getsockname()[0]
    except Exception:
        ip = '127.0.0.1'  # 失败时返回本地地址
    finally:
        s.close()
    return ip