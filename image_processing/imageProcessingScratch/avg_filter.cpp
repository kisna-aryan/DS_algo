#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main()
{   
    String imageName("images/image.jpg" ); // by default
    Mat image;
    image = imread( samples::findFile( imageName ), IMREAD_UNCHANGED ); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    [int newImageRows, int newImageCols, int che] = image.size(); 
    Mat newImage(newImageRows,newImageCols, che);

    for(int i = 1; i < newImageCols; i++)
    {
        for(int j = 1; j < newImageRows; j++)
        {
            newImage.at<Vec3b>(i,j) = (image.at<Vec3b>(i + 1, j + 1) +  image.at<Vec3b>(i+ 1 , j)+  image.at<Vec3b>(i + 1 , j - 1) +  image.at<Vec3b>(i - 1, j)+  image.at<Vec3b>(i -1 , j + 1)+  image.at<Vec3b>(i - 1, j -1)+  image.at<Vec3b>(i, j) + image.at<Vec3b>(i, j + 1) +  image.at<Vec3b>(i, j -1))/9;

        }
    }

        namedWindow( "Original Images", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Original Images", image );    

    namedWindow( "Cropped Image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Cropped Image", newImage );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
