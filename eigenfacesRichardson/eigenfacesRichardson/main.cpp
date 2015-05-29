

#include "Util.h"
#include "Eigenface.h"
#include <iostream>

int main() { 

	std::vector<cv::Mat> images;
	cv::Mat richardson = cv::imread("faces/b0.png");

	for (int i = 1; i <= 10; i++){
		std::string path = "faces/b" + std::to_string(i) + ".png";
		cv::Mat im = cv::imread(path);
		images.push_back(im);
		std::cout << "loading: " << path << " " << !im.empty() << std::endl;
	}

	Eigenface e(images); 
	std::cout << "eigen values\n" << e.eigenvalues << std::endl;
	std::cout << "eigen vectors\n" << e.eigenvectors << std::endl;

	
	cv::Mat richardson_row = eigen::singleAsRowMatrix(richardson, richardson_row.type());
	cv::Mat projection = e.project(richardson_row);
	cv::Mat reconstruction = e.reconstruct(richardson_row);
	//cv::normalize(m4_r, m4_r, 0, 255, CV_MINMAX);
	//std::cout << "normalized: " << m4_r << std::endl;
	//std::cout << "reconstructed: " << tmp << std::endl;


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