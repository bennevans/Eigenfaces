
#ifndef EIGEN_UTIL_H
#define EIGEN_UTIL_H

#include <vector>
#include <opencv2\opencv.hpp>


namespace eigen{
	cv::Mat asRowMatrix(const std::vector<cv::Mat> images, int type){

		int n = images.size();

		if (n == 0)
			return cv::Mat();

		int d = images[0].total();

		cv::Mat data(n, d, type);

		for (int i = 0; i < n; i++){
			if (images[i].total() != d)
				CV_Error(CV_StsError, "Images are not all the same size!");

			cv::Mat xi = data.row(i);
			images[i].clone().reshape(1, 1).convertTo(xi, type, 1, 0);
		}

		return data;

	}
};

#endif