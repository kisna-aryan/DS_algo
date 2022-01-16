// Import dependencies
#include <opencv2/opencv.hpp>
#include <iostream>
// Using namespaces to nullify use of c::function(); syntax and std::function(); syntax
using namespace std;
using namespace cv;
int main()
{
    // Read Images
    Mat img = imread("../images/image.jpg");
    if(img.empty())
    {
        cout<<"Image not found"<<endl;
        return -1;
    }
    // Display Image
    imshow("Original Image", img);
    waitKey();
    // Print Error message if image is null
    if (img.empty())
        {
            cout << "Could not read image" << endl;
        }
    // Draw line on image
    Mat imageLine = img.clone();
    Point pointA(200,80);
    Point pointB(450,80);
    line(imageLine, pointA, pointB, Scalar(255, 255, 0), 3, 8, 0);
    imshow("Lined Image", imageLine);
    waitKey();
}