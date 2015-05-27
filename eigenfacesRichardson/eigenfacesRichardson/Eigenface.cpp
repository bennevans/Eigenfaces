#include "Eigenface.h"

#include "Util.h"

Eigenface::Eigenface(std::vector<cv::Mat> images)
{
	compute(images);
}


Eigenface::~Eigenface()
{
}

void Eigenface::compute(std::vector<cv::Mat> images){

	if (images.size() == 0)
		CV_Error(CV_StsUnsupportedFormat, "Empty training set");

	cv::Mat data = eigen::asRowMatrix(images, CV_64FC1);
	
	int n = data.rows;
	int d = data.cols;

	cv::PCA pca(data, cv::Mat(), CV_PCA_DATA_AS_ROW, n);

	meanImage = pca.mean.reshape(1, 1);
	eigenvectors = pca.eigenvectors.t();
	eigenvalues = pca.eigenvalues.clone();


}	


cv::Mat Eigenface::project(cv::Mat image){
	
	cv::Mat	W = eigenvectors;
	cv::Mat mean = meanImage;

	int n = image.rows;
	int d = image.cols;

	if (W.rows != d)
		CV_Error(CV_StsUnmatchedSizes, "Matricies not the right size!");

	cv::Mat X, Y;

	image.convertTo(X, W.type());

	for (int i = 0; i < n; i++){
		cv::Mat r_i = X.row(i);
		subtract(r_i, mean.reshape(1, 1), r_i);
	}

	gemm(X, W, 1.0, cv::Mat(), 0.0, Y);
	return Y;

}