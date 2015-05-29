

#include "Util.h"
#include "Eigenface.h"
#include <iostream>

int main() { 

	std::vector<cv::Mat> images;

	//cv::Mat m23 = cv::imread("Richardson.jpg", 0); 
	//if(m23.empty()) { 
	//			std::cout << "EMPTY RICHARDSON" << std::endl;
	//}
	cv::Mat m1(2, 2, CV_64FC1);
	cv::Mat m2(2, 2, CV_64FC1);
	cv::Mat m3(2, 2, CV_64FC1);


	m1 = cv::Mat::eye(cv::Size(2, 2), CV_64FC1)*6 + cv::Mat::ones(cv::Size(2, 2), CV_64FC1)*5;
	m2.setTo(cv::Scalar(255));
	m3 = cv::Mat::eye(cv::Size(2, 2), CV_64FC1) * 255 / 2 + 2*cv::Mat::ones(cv::Size(2,2), CV_64FC1);

		std::string file = "Eigenfaceslapic\\1.png";
		images.push_back(cv::imread(file, 0));
		std::string file1 = "Eigenfaceslapic\\2.png";
		images.push_back(cv::imread(file, 0));
		std::string file2 = "Eigenfaceslapic\\3.png";
		images.push_back(cv::imread(file, 0));

	//images.push_back(m1);
	//images.push_back(m2);
	//images.push_back(m3);

	//std::cout << m1 << std::endl;
	//std::cout << m2 << std::endl;
	//std::cout << m23 << std::endl;

	Eigenface e(images); 

	//std::cout << "eigen values\n" << e.eigenvalues << std::endl;
	//std::cout << "eigen vectors\n" << e.eigenvectors << std::endl;

	//double m4_data[] = { 136.5, 258, 258, 136.5 };
	//cv::Mat m4 = cv::imread("Eigenfaceslapic\\0.png", 0);

	//cv::Mat m4_r = eigen::singleAsRowMatrix(m4, m4.type());

	//std::cout << "m4:\n" << m4 << std::endl;
	//std::cout << "row matrix: " << m4_r << std::endl;
	//m4_r = e.project(m4_r);
	//std::cout << "project: " << m4_r << std::endl;
	//cv::Mat tmp = m4_r.clone();
	//tmp = e.reconstruct(m4_r);
	//cv::normalize(m4_r, m4_r, 0, 255, CV_MINMAX);
	//std::cout << "normalized: " << m4_r << std::endl;
	//std::cout << "reconstructed: " << tmp << std::endl;
	getchar();
	return 0;
}