

import java.util.ArrayList;

import org.opencv.core.*;
import org.opencv.highgui.Highgui;

public class EigenfacesMain {

	public static void main(String args[]){
		System.loadLibrary(Core.NATIVE_LIBRARY_NAME);

		//steps according to wikipedia
		
		//Load all images into matricies
		//Convert matricies into vectors
		//store said vectors into a single matrix T where each column is a vector
		//calculate the average image a
		//subtract the mean from each image in T
		//calculate the eigenvectors and values of the covariance matrix 
		//see Core.PCACompute(data, mean, eigenvectors);
		//sort the eigenvalues descending with their corresponding eigenvectors
	
		
		Mat m1 = Mat.eye(new Size(2, 2), CvType.CV_8UC1);
		Mat m2 = Mat.eye(new Size(2, 2), CvType.CV_8UC1);
		Core.multiply(m2, new Scalar(2), m2);
		ArrayList<Mat> mats = new ArrayList<>();
		mats.add(m1);
		mats.add(m2);
		Eigenfaces e = new Eigenfaces(mats);
		System.out.println(e.calculateImageMatrix(mats).dump());
	}
	
}
