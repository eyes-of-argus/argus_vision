#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>

int main(int argc, char const * argv[])
{
	std::istringstream arg1, arg2;
	int left_id, right_id;

	if(argc != 3)
	{
		std::cerr << "Not enough arguments provided. Usage:\n"
		<< "camera_check ""left_camera_id"" ""right_camera_id""\n";
		return 1;
	}

	arg1.str(argv[1]);
	arg2.str(argv[2]);

	if(!(arg1 >> left_id))
	{
		std::cerr << "Invalid left camera id. Must be an int\n";
		return 1;
	}
	if(!(arg2 >> right_id))
	{
		std::cerr << "Invalid right camera id. Must be an int\n";
		return 1;
	}

	cv::VideoCapture left_cam(left_id);
	cv::VideoCapture right_cam(right_id);
	if(!right_cam.isOpened() || !left_cam.isOpened())
		return 1;

	cv::Mat left_image, right_image;
	//cv::Mat right_resize, left_resize;

	while(1)
	{
		
		left_cam.grab();
		right_cam.grab();

		left_cam.retrieve(left_image);
		right_cam.retrieve(right_image);

		//cv::resize(right_image, right_resize, cv::Size(1280, 720));
		//cv::resize(left_image, left_resize, cv::Size(1280, 720));
		cv::imshow("left", left_image);
		cv::imshow("right", right_image);
		cv::waitKey(10);
	}

	return 0;
}
