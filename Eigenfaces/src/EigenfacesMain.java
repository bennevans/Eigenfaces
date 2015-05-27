

import java.util.ArrayList;

import org.opencv.contrib.Contrib;
import org.opencv.contrib.FaceRecognizer;
import org.opencv.core.*;

public class EigenfacesMain {

	public static void main(String args[]){
		System.loadLibrary(Core.NATIVE_LIBRARY_NAME);

		
		Mat m1 = Mat.eye(new Size(2, 2), EigenUtil.TYPE);
		Mat m2 = Mat.eye(new Size(2, 2), EigenUtil.TYPE);
		Mat m3 = Mat.eye(new Size(2, 2), EigenUtil.TYPE);
		Core.multiply(m2, new Scalar(255), m2);
		m3.put(0, 0, 50);
		m3.put(1, 0, 32);
		m3.put(0,1,255);
		
		ArrayList<Mat> mats = new ArrayList<>();
		mats.add(m1);
		mats.add(m2);
		mats.add(m3);
		Eigenfaces e = new Eigenfaces(mats);
		System.out.println(e);
		System.out.println("normalized:\n"+EigenUtil.normalize(e.project(m3)).dump());

		
		for(Mat m : e.getEigenvectors()){
			m = EigenUtil.normalize(m);
			System.out.println("eigen vector: " + m.dump());
		}
		
		
		
	}
	
}
