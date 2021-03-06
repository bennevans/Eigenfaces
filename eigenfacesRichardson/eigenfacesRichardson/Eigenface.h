
#pragma once

#ifndef EIGEN_H
#define EIGEN_H

#include <opencv2/opencv.hpp>
#include <vector>


class Eigenface
{
public:
	Eigenface(std::vector<cv::Mat>);
	~Eigenface();

	void compute(std::vector<cv::Mat>);
	cv::Mat project(cv::Mat);
	cv::Mat reconstruct(cv::Mat);

	cv::Mat meanImage;
	cv::Mat eigenvectors;
	cv::Mat eigenvalues;

	std::vector<cv::Mat> eigenFaces();
};

#endif