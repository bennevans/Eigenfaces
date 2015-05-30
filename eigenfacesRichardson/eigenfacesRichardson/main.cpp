

#include "Util.h"
#include "Eigenface.h"
#include <iostream>

int main() { 

	std::vector<cv::Mat> images;
	cv::Mat richardson = cv::imread("faces/b0.png");
	cv::cvtColor(richardson, richardson, CV_64FC1);

	for (int i = 0; i <= 10; i++){

		std::string path = "faces/b" + std::to_string(i) + ".png";
		cv::Mat im = cv::imread(path);
		std::cout << "loading: " << path << " " << !im.empty() << std::endl;

		cv::cvtColor(im, im, CV_64FC1);
		images.push_back(im);

		cv::namedWindow(path);
		cv::imshow(path, im);
	}

	Eigenface e(images); 

	
	cv::Mat richardson_row = eigen::singleAsRowMatrix(richardson, richardson.type());
	cv::Mat projection = e.project(richardson_row);
	cv::Mat reconstruction = e.reconstruct(projection);
	cv::normalize(projection, projection, 0, 255, CV_MINMAX);
	cv::normalize(reconstruction, reconstruction, 0, 255, CV_MINMAX);

	std::cout << projection << std::endl;

	for (int i = 0; i < e.eigenFaces().size(); i++){
		cv::Mat tmp;
		cv::Mat tmp2;
		e.eigenFaces()[i].copyTo(tmp);
		cv::normalize(tmp, tmp, CV_MINMAX);
		((cv::Mat)(255*tmp)).convertTo(tmp2, CV_8UC1);
		cv::namedWindow(std::to_string(i));
		cv::imshow(std::to_string(i), tmp2);
	}

	cv::Mat proj(100,75,CV_64FC1);
	cv::Mat imageCombo(100, 75, CV_8UC1);

	for (int i = 0; i < projection.cols; i++){
		cv::Mat single = e.eigenFaces()[i]*projection.at<double>(0,i);
		proj = proj + single;
	}

	cv::normalize(proj, proj, 0,1, CV_MINMAX);


	cv::namedWindow("Projection", CV_WINDOW_NORMAL);
	cv::imshow("Projection", proj);
	cv::imshow("Richardson", richardson);

	cv::waitKey(0);
	return 0;
}