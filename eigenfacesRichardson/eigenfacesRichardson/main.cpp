

#include "Util.h"
#include "Eigenface.h"
#include <iostream>

int main() { 

	std::vector<cv::Mat> images;

	cv::Mat m23 = cv::imread("c:\\Eigenfaces\\Eigenfaceslapics\\Richardson.jpg", 0); 
	if(m23.empty()) {  
		return -1;
	}
	cv::Mat m1(2, 2, CV_64FC1);
	cv::Mat m2(2, 2, CV_64FC1);
	cv::Mat m3(2, 2, CV_64FC1);


	m1 = cv::Mat::eye(cv::Size(2, 2), CV_64FC1)*6 + cv::Mat::ones(cv::Size(2, 2), CV_64FC1)*5;
	m2.setTo(cv::Scalar(255));
	m3 = cv::Mat::eye(cv::Size(2, 2), CV_64FC1) * 255 / 2 + 2*cv::Mat::ones(cv::Size(2,2), CV_64FC1);

	images.push_back(m1);
	images.push_back(m2);
	images.push_back(m3);

	//std::cout << m1 << std::endl;
	//std::cout << m2 << std::endl;
	std::cout << m23 << std::endl;

	Eigenface e(images); 

	std::cout << "eigen values\n" << e.eigenvalues << std::endl;
	std::cout << "eigen vectors\n" << e.eigenvectors << std::endl;

	cv::Mat m4_r = eigen::singleAsRowMatrix(m3, m3.type());
	std::cout << "row matrix: " << m4_r << std::endl;
	m4_r = e.project(m4_r);
	std::cout << "project: " << m4_r << std::endl;
	cv::Mat tmp = m4_r.clone();
	tmp = e.reconstruct(m4_r);
	cv::normalize(m4_r, m4_r, 0, 255, CV_MINMAX);
	std::cout << "normalized: " << m4_r << std::endl;
	std::cout << "reconstructed: " << tmp << std::endl;
	cv::normalize(tmp, tmp, 0, 255, CV_MINMAX);
	std::cout << "normalized: " << tmp << std::endl;

	getchar();
	return 0;
}