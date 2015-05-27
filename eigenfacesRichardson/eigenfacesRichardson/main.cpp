

#include "Util.h"
#include "Eigenface.h"
#include <iostream>

int main() { 

	std::vector<cv::Mat> images;

	cv::Mat m1(2, 2, CV_64FC1);
	cv::Mat m2(2, 2, CV_64FC1);
	cv::Mat m3(2, 2, CV_64FC1);

	m1.setTo(cv::Scalar(0));
	m2.setTo(cv::Scalar(255));
	m3 = cv::Mat::eye(cv::Size(2, 2), CV_64FC1) * 255 / 2 - 1;
	cv::Mat m4 = m3.clone();

	images.push_back(m1);
	images.push_back(m2);
	images.push_back(m3);

	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m3 << std::endl;

	Eigenface e(images); 
	std::cout << "29" << std::endl;
	cv::Mat m4_r = eigen::singleAsRowMatrix(m4, 0);
	std::cout << "31" << std::endl;
	std::cout << e.project(m4) << std::endl;
	std::cout << "33" << std::endl;

	getchar();
	return 0;
}