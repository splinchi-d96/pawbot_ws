from setuptools import find_packages, setup
import glob
import os

package_name = 'topic_py'

# 源资源根目录（相对于setup.py的路径）
source_root = 'topic_py/lib/zsl-1'

# 获取所有文件（含子目录）并过滤出文件
files = [f for f in glob.glob(
    f'{source_root}/**/*', recursive=True) if os.path.isfile(f)]

# 构建data_files：直接按文件相对路径生成目标目录
data_files = [
    ('share/ament_index/resource_index/packages',
     ['resource/' + package_name]),
    ('share/' + package_name, ['package.xml']),
]
for file in files:
    # 计算文件相对于源根的路径（如"x86_64/lib.so"）
    rel_path = os.path.relpath(file, source_root)
    # 目标目录 = 目标根 + 相对路径的目录部分（保留子文件夹）
    target_dir = os.path.join(f'share/{package_name}/lib/zsl-1', os.path.dirname(rel_path))
    data_files.append((target_dir, [file]))

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    # 递归获取 topic_py/lib/zsl-1/ 下的所有文件
    data_files=data_files,
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='spl',
    maintainer_email='spl@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'group_control_node = topic_py.group_control_node:main',
            'robot_node = topic_py.robot_node:main',
            'robot_battle = topic_py.robot_battle:main',
        ],
    },
)
