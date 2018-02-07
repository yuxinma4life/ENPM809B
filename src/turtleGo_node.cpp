#include "ros/ros.h"
#include "geometry_msgs/Twist.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtleGo_node");
  ros::NodeHandle nh;
  ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",100);
  geometry_msgs::Twist vel;
  vel.linear.x = 0.5;
  vel.linear.y = 0.5;
  vel.angular.z = 0.2;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {

    //ROS_INFO_STREAM("I'm saying" <<vel.x);

    vel_pub.publish(vel);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
