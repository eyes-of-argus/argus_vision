// M. Kaan Tasbas | mktasbas@gmail.com

/* Subscribes to published disparity images, stores most recent of each baseline,
 * then combines them into a single disparity image
 */

#include "ros/ros.h"
#include "stereo_msgs/DisparityImage.h"

#include <sstream>

void disparityCallback(const stereo_msgs::DisparityImage::ConstPtr& msg)
{
	ROS_INFO("\nData Received:\n");
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "disparity");
	ros::NodeHandle n;
	ros::Subscriber d_image = n.subscribe("/stereo/disparity", 5, disparityCallback);
	ros::spin();
	return 0;
}