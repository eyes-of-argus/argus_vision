// M. Kaan Tasbas | mktasbas@gmail.com

/* Subscribes to published disparity images, stores most recent of each baseline,
 * then combines them into a single disparity image
 */

#include "ros/ros.h"
#include "stereo_msgs/DisparityImage.h"
#include "cv_bridge/cv_bridge.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <sstream>

void disparityCallback(const stereo_msgs::DisparityImageConstPtr& msg)
{
	// convert ROS image to OpenCV image
	cv_bridge::CvImageConstPtr cv_ptr;
	cv_ptr = cv_bridge::toCvShare(msg->image, msg, msg->image.encoding);

	// print image to screen using OpenCV
	cv::imshow("Disparity Image", cv_ptr->image);
	cv::waitKey(30);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "disparity");
	ros::NodeHandle n;
	// create openCV display window
	cv::namedWindow("Disparity Image");
	// get image from published topic
	ros::Subscriber d_image = n.subscribe("/stereo/disparity", 5, disparityCallback);
	ros::spin();
	// free openCV display window
	cv::destroyWindow("Disparity Image");
	return 0;
}