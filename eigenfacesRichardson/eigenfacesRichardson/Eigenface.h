
#ifndef EIGEN_H
#define EIGEN_H

#include <opencv2/opencv.hpp>

class Eigenface
{
public:
	Eigenface();
	~Eigenface();

	void compute();
	cv::Mat project();
};

#endif