// This program publishes randomly-generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>  // For geometry_msgs::Twist
#include <stdlib.h> // For rand() and RAND_MAX

int main(int argc, char **argv) {
  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "publish_velocity");
  ros::NodeHandle nh;

  //The work of actually publishing the messages is done by an object of class ros::Publisher
  // Create a publisher object.

  //The node_handle is an object of class ros::NodeHandle, one that you created near the start of your program. 
  //We’re calling the advertise method of that object.

  //The message_type part inside the angle brackets—formally called the template parameter—is the data type for the 
  //messages we want to publish. This should be the name of the class defined in the header discussed above. 
  //In the example, we use the geometry_msgs::Twist class.

  //The last parameter to advertise is an integer representing the size of the message queue
  // for this publisher. In most cases, a reasonably large value, say 1000, is suitable. 
  //If your program rapidly publishes more messages than the queue can hold, the
  //oldest unsent messages will be discarded.
  ros::Publisher  pub = nh.advertise < geometry_msgs::Twist
> ("/mobile_base/commands/velocity", 1);

  // Seed the random number generator.
  srand(time(0));

  // Loop at 2Hz until the node is shut down.
  ros::Rate rate(2);
  while(ros::ok()) {
    // Create and fill in the message.  The other four
    // fields, which are ignored by turtlesim, default to 0.
    geometry_msgs::Twist msg;
    msg.linear.x = double(rand())/double(RAND_MAX);
    msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

    // Publish the message.
    pub.publish(msg);

    // Send a message to rosout with the details.
    ROS_INFO_STREAM("Sending random velocity command:"
      << " linear=" << msg.linear.x
      << " angular=" << msg.angular.z);

    // Wait until it's time for another iteration.
    rate.sleep();
  }
}
