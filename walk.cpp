/*
 *@brief This package is to randomly move turtlebot
 *@Author: Project Group 5
 *
 */

#include <stdlib.h>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv) {

	// initialize node named walk
	ros::init(argc, argv, "walk");

	// create nodeHandle
	ros::NodeHandle n;

	// publish message to topic /mobile_base/commands/velocity
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity",1000);

	// seed the random number genertor
	srand(time(0));

	// Loop rate 2 Hz
	ros::Rate rate(2);

	while(ros::ok()) {

		// set up linear and angular velocity for turtlebot
		geometry_msgs::Twist msg;
		msg.linear.x = double(rand())/double(RAND_MAX);
		msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

		// publish the message
		pub.publish(msg);

	    // Send a message to rosout with the details.
	    ROS_INFO_STREAM("Sending random velocity command:" \
	    		<< " linear=" << msg.linear.x \
				<< " angular=" << msg.angular.z);

	    // Wait until it's time for another iteration.
		rate.sleep();
	}


}


