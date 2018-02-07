# ENPM809B

Install-
```
 sudo apt-get install ros-<distro>-turtlebot-apps ros-<distro>-turtlebot-rviz-launchers
 
```

Bring-up
```
roslaunch turtlebot_bringup minimal.launch --screen

```
Gazebo launch
```
roslaunch turtlebot_gazebo turtlebot_world.launch
```

keyop for controlling turtlebot with keyboard
```
roslaunch kobuki_keyop keyop.launch
```

run hello code that has lecture tutorial random move commands in with proper topic
```
cd <repo_directory>
source devel/setup.bash
catkin_make
rosrun my_first_package hello
```
The turtlebot should run randomly in curves
