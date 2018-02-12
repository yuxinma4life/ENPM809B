# ENPM809B

## Pre-requirement

- ROS Kinetic 16.04
- Gazebo
- Turtlebot
- git

## Install-
```
 sudo apt-get install ros-<distro>-turtlebot-apps ros-<distro>-turtlebot-rviz-launchers

```
## Build
In the workspace src folder
```
git clone -b Zejiang https://github.com/yuxinma4life/ENPM809B
```
Back to the workspace (catkin_ws)
```
catkin_make
```

## Run
### Run the single node
```
rosrun turtleGo turtleGo_node
```
### Check the topic content
```
rostopic echo /cmd_vel_mux/input/teleop
```
### Visilization in Gazebo
```
roslaunch turtleGo turtleforandom.launch
```
![Empty_world](https://github.com/yuxinma4life/ENPM809B/blob/Zejiang/result/gazebo.png)
### Visualizing the ROS computation graph in rqt
```
rqt_graph
```
![rqt_graph](https://github.com/yuxinma4life/ENPM809B/blob/Zejiang/result/rqt_graph.png)
