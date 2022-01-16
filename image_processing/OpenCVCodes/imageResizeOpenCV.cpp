// let's start with including libraries 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main()
{
	// Read the image using imread function
	Mat image = imread("../images/image.jpg");
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	imshow("Original Image", image);


	// let's downscale the image using new  width and height
	int down_width = image.cols / 2;
	int down_height = image.rows / 2;
	Mat resized_down;
	//resize down
	resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
	// let's upscale the image using new  width and height
	int up_width = image.cols * 2;
	int up_height = image.rows * 2;
	Mat resized_up;
	//resize up
	resize(image, resized_up, Size(up_width, up_height), INTER_LINEAR);
	// Display Images and press any key to continue
	imshow("Resized Down by defining height and width", resized_down);
	waitKey();
	imshow("Resized Up image by defining height and width", resized_up);
	waitKey();


	destroyAllWindows();
	return 0;
}