// #include <opencv2/core.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    String imageName("images/FLIR_video_00001.jpeg" ); // by default
    Mat image;
    image = imread(samples::findFile( imageName ), IMREAD_UNCHANGED); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    int newImageRows = image.rows*2;
    int newImageCols = image.cols*2;
    Mat newImage(newImageRows, newImageCols, CV_8UC1);
    for(int i = 0; i < newImageRows; i++)
    {
        for(int j = 0; j < newImageCols; j++)
        {
            newImage.at<uchar>(i,j) = image.at<uchar>(i/2,j/2,0);
        }
    }
    namedWindow( "Original Images", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Original Images", image );    

    namedWindow( "Zoomed Image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Zoomed Image", newImage );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}