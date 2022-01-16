#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int, char**) 
{
    Mat image = imread("../images/image.jpg");
    if(image.empty())
    {
        cout<<"Image not found"<<endl;
        return -1;
    }
	  imshow("image", image);
	  waitKey(0);
	  double angle = 45;

	  // get the center coordinates of the image to create the 2D rotation matrix
	  Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
	  // using getRotationMatrix2D() to get the rotation matrix
	  Mat rotation_matix = getRotationMatrix2D(center, angle, 1.0);

	  // we will save the resulting image in rotated_image matrix
	  Mat rotated_image;
	  // rotate the image using warpAffine
	  warpAffine(image, rotated_image, rotation_matix, image.size());
	  imshow("Rotated image", rotated_image);
    // wait indefinitely, press any key on keyboard to exit
	  waitKey(0);
	  // save the rotated image to disk
	//   imwrite("rotated_im.jpg", rotated_image);

	  return 0;
}
