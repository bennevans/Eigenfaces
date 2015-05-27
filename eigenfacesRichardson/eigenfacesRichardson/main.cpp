

#include "Eigenface.h"
#include <iostream>

int main() { 

	std::vector<cv::Mat> images;

	cv::Mat m1(2, 2, CV_8UC1);
	cv::Mat m2(2, 2, CV_8UC1);
	cv::Mat m3(2, 2, CV_8UC1);

	m1.at<int>(cv::Point(0,0)) = 255;
	std::cout << m1 << std::endl;
	Eigenface e(images); 
	
	return 0;
}