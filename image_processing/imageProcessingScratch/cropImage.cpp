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
    String imageName("../images/image.jpg" ); // by default
    Mat image;
    image = imread(samples::findFile( imageName ), IMREAD_UNCHANGED); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    cout << "Image size: " << image.size() << endl;
    cout << "Image channels: " << image.channels() << endl;
    cout << "Image rows: " << image.rows << endl;
    cout << "Image cols: " << image.cols << endl;
    int crop_x1 = 0;
    int crop_y1 = 0;
    int crop_x2 = 200;  
    int crop_y2 = 280;

    int newImageRows = crop_y2 - crop_y1;
    int newImageCols = crop_x2 - crop_x1;

    Mat newImage(newImageCols,newImageRows, image.type());

    cout << "New Image size: " << newImage.size() << endl;
    cout << "New Image channels: " << newImage.channels() << endl;
    cout << "New Image rows: " << newImage.rows << endl;
    cout << "New Image cols: " << newImage.cols << endl;

    for(int i = 0; i < newImageCols; i++)
    {
        for(int j = 0; j < newImageRows; j++)
        {
            newImage.at<Vec3b>(i,j) = image.at<Vec3b>(crop_y1+i, crop_x1+j);

        }
    }
    namedWindow( "Original Images", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Original Images", image );    

    namedWindow( "Cropped Image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Cropped Image", newImage );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}