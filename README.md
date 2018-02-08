# ENPM809B Assigment 1

## This assignment is to implement a ros node to randomly run turtlebot. 

### Install essential ROS packages:
```
 sudo apt-get install ros-<distro>-turtlebot-apps ros-<distro>-turtlebot-rviz-launchers
 
```
### Clone repo to ros workspace, e.g. catkin_ws
```
 git clone https://github.com/yuxinma4life/ENPM809B.git
```
### Build package
```
 cd ~/catkin_ws
 catkin_make
```
### Run node from launch file
```
 source devel/setup.bash
 roslaunch simple_walk simple_walk.launch
```
### Change gazebo world for running turtlebot, e.g. playground.world
```
 roslaunch simple_walk simple_walk.launch world_file:=$(rospack find turtlebot_gazebo)/worlds/playground.world
```
