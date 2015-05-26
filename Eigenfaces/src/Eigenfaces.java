import java.util.ArrayList;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.highgui.Highgui;
import org.opencv.photo.Photo;


public class Eigenfaces {

	private Mat imageMatrix;
	private Mat meanImage;
	
	public Eigenfaces(ArrayList<Mat> images){
		
	}
	
	public Mat calculateImageMatrix(ArrayList<Mat> images){
		if(images.size() == 0)
			throw new IllegalArgumentException("No images...");
		if(images.get(0).type() != CvType.CV_8UC1)
			throw new IllegalArgumentException("Image is not b&w");
		
		int rows = images.get(0).rows();
		int cols = images.get(0).cols();
		int d = (int)images.get(0).total();
		int n = images.size();
		
		Mat ret = new Mat(d, n, CvType.CV_8UC1);
		
		for(int i = 0; i < n; i++){
			if(images.get(i).total() != d)
				throw new IllegalArgumentException("Images are not the same size");
			
			Mat col = ret.col(i);
			images.get(i).reshape(0,d).copyTo(col);
		}
		
		return ret;
	}
	
	private Mat calculateMeanImage(ArrayList<Mat> images){
		return new Mat();
	}
	
}
