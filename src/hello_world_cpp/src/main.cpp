#include "ros/ros.h"
#include <iostream>

/**
 * This tutorial demonstrates how to initialize a node and prints out a message.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "print_hello_word");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  
  /**
   * Initialize the rate object and set the frequency to 1hz. 
   */
  ros::Rate loop_rate(1);

  /**
   * A count of how many messages we print.
   */
  int count = 1;
  while (ros::ok())
  {
     std::cout<< count << " - " << "Hello World!" <<std::endl;
     loop_rate.sleep();
     ++count;
  } 

    return 0;
}