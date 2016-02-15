
#pragma once
#ifndef EIGEN_UTIL_H
#define EIGEN_UTIL_H

#include <vector>
//#include <opencv2\opencv.hpp>
#include <opencv2/opencv.hpp>

namespace eigen{
	inline cv::Mat asRowMatrix(const std::vector<cv::Mat> images, int type){

		std::cout << "asRowMatrix" << std::endl;

		int n = images.size();

		if (n == 0)
			return cv::Mat();

		int d = images[0].total();

		cv::Mat data(n, d, type);

		std::cout << "converting..." << std::endl;

		for (int i = 0; i < n; i++){
			if (images[i].total() != d)
				CV_Error(CV_StsError, "Images are not all the same size!");

			cv::Mat xi = data.row(i);
			images[i].clone().reshape(1, 1).convertTo(xi, type, 1, 0);
		}


		return data;

	}


	inline cv::Mat singleAsRowMatrix(cv::Mat image, int type){

		if (image.channels() != 1)
			CV_Error(CV_StsBadSize, "Image not one channel");

		int d = image.total();

		cv::Mat data(1, d, type);
	
		cv::Mat xi = data.row(0);
		
		if (image.isContinuous())
			image.reshape(1, 1).convertTo(xi, type, 1, 0);
		else
			image.clone().reshape(1, 1).convertTo(xi, type, 1, 0);

		return data;

	}

};

#endif
