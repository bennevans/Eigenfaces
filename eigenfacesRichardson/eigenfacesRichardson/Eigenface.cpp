
#include "Util.h"
#include "Eigenface.h"



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
	
	std::cout << "project()" << std::endl;

	cv::Mat	W = eigenvectors;
	cv::Mat mean = meanImage;


	std::cout << "project, asRowMatrix()" << std::endl;


	std::cout << "nd" << std::endl;

	int n = image.rows;
	int d = image.cols;


	std::cout << "assert()" << std::endl;

	if (W.rows != d){
		std::cout << "W " << W << " d " << d << std::endl;
		CV_Error(CV_StsUnmatchedSizes, "Matricies not the right size!");
	}
	cv::Mat X, Y;


	std::cout << "convertTo()" << std::endl;

	image.convertTo(X, W.type());

	std::cout << "subtract()" << std::endl;

	for (int i = 0; i < n; i++){
		cv::Mat r_i = X.row(i);
		subtract(r_i, mean.reshape(1, 1), r_i);
	}


	std::cout << "gemm()" << std::endl;

	gemm(X, W, 1.0, cv::Mat(), 0.0, Y);
	return Y;

}