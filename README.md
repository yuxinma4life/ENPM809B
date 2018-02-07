# ENPM809B

## Pre-requirement

-ROS Kinetic 16.04
-Gazebo


## Install-
```
 sudo apt-get install ros-<distro>-turtlebot-apps ros-<distro>-turtlebot-rviz-launchers

```
## Build
In the workspace (catkin_ws)
```
catkin_make
```

## Run
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
