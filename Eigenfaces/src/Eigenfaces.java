import java.util.ArrayList;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;

public class Eigenfaces {

	private Mat imageMatrix;
	private Mat meanImage;
	
	public Eigenfaces(ArrayList<Mat> images){
		imageMatrix = calculateImageMatrix(images);
		meanImage = calculateMeanImage(imageMatrix);
		subtractMean();
	}
	
	private Mat calculateImageMatrix(ArrayList<Mat> images){
		if(images.size() == 0)
			throw new IllegalArgumentException("No images...");
		if(images.get(0).type() != CvType.CV_64FC1)
			throw new IllegalArgumentException("Image is not b&w");
		
		int d = (int)images.get(0).total();
		int n = images.size();
		
		Mat ret = new Mat(d, n, CvType.CV_64FC1);
		
		for(int i = 0; i < n; i++){
			if(images.get(i).total() != d)
				throw new IllegalArgumentException("Images are not the same size");
			
			Mat col = ret.col(i);
			images.get(i).reshape(0,d).copyTo(col);
		}
		
		return ret;
	}
	
	private Mat calculateMeanImage(Mat imageMat){
		int rows = imageMat.rows();
		int cols = imageMat.cols();
		Mat ret = Mat.zeros(rows, 1, CvType.CV_64FC1);//new Mat(rows, 1, CvType.CV_8UC1);
		
		for(int i = 0; i < cols; i++){			
			Core.add(ret, imageMat.col(i), ret);
		}
		
		Core.multiply(ret, new Scalar(1.0/cols),ret);
		
		return ret;
	}
	
	private void subtractMean(){
		Mat ret = imageMatrix.clone();
				
		for(int i = 0; i < ret.cols(); i++){
			Core.subtract(ret.col(i), meanImage, ret.col(i));
		}
		
		imageMatrix = ret;
	}
	
	public String toString(){
		return imageMatrix.dump();
	}
	
}
