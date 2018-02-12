/**
 * @Author: Zejiang Zeng , Pranav Dhulipala, Shaotu Jia, Yuxin Ma, Ori Perl
 * @Date:   2018-02-12T15:47:28-05:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Last modified time: 2018-02-12T16:33:34-05:00
 * @License: BSD
 * @Brief: This program publishes randomly-generated velocity messages for turtlebot
 */



#include "ros/ros.h"
#include "geometry_msgs/Twist.h" // For geometry_msgs::Twist
#include <stdlib.h> // For rand() and RAND_MAX


int main(int argc, char **argv)
{
        // Initialize the ROS system and become a node.
        ros::init(argc, argv, "turtleGo_node");
        ros::NodeHandle nh;
        /**The work of actually publishing the messages is done by an object of class ros::Publisher
            Create a publisher object.

           The node_handle is an object of class ros::NodeHandle, one that you created near the start of your program.
           We’re calling the advertise method of that object.

           The message_type part inside the angle brackets—formally called the template parameter—is the data type for the
           messages we want to publish. This should be the name of the class defined in the header discussed above.
           In the example, we use the geometry_msgs::Twist class.

           The last parameter to advertise is an integer representing the size of the message queue
           for this publisher. In most cases, a reasonably large value, say 100, is suitable.
           If your program rapidly publishes more messages than the queue can hold, the
           oldest unsent messages will be discarded.
         **/
        ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",100);
        // set up linear and angular velocity for turtlebot
        geometry_msgs::Twist vel;
        vel.linear.x = 0.5;
        vel.angular.z = 0.2;
        /**
         * OR generate random velocity
         */
        // Seed the random number genertor
        //  srand(time(0));

        // Loop at 10Hz until the node is shut down.
        ros::Rate loop_rate(10);
        while(ros::ok()) {

                //  vel.linear.x = double(rand())/double(RAND_MAX);
                //  vel.angular.z = 2*double(rand())/double(RAND_MAX) - 1;


                // publish the message
                vel_pub.publish(vel);

                ros::spinOnce();

                loop_rate.sleep();
        }

        return 0;
}
