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

    int newImageRows = image.rows*2;
    int newImageCols = image.cols*2;
    Mat newImage(newImageRows,newImageCols, image.type());

        cout << "Image size: " << newImage.size() << endl;
    cout << "Image channels: " << newImage.channels() << endl;
    cout << "Image rows: " << newImage.rows << endl;
    cout << "Image cols: " << newImage.cols << endl;

    for(int i = 0; i < newImageRows; i++)
    {
        for(int j = 0; j < newImageCols; j++)
        {
            // Vec3b intensity = image.at<Vec3b>(i/2,j/2);
            // Vec3b intensity1 = image.at<Vec3b>((i+1)/2,(j+1)/2);
            // unsigned char blue = (image.at<Vec3b>(i/2,j/2)[0] + image.at<Vec3b>((i+1)/2,(j+1)/2)[0])/2;
            // unsigned char green = (image.at<Vec3b>(i/2,j/2)[1] + image.at<Vec3b>((i+1)/2,(j+1)/2)[1])/2;
            // unsigned char red = (image.at<Vec3b>(i/2,j/2)[2] + image.at<Vec3b>((i+1)/2,(j+1)/2)[2])/2;

            // newImage.at<Vec3b>(i,j) = {blue,green,red};
            // newImage.at<Vec3b>(i,j) = (image.at<Vec3b>(i/2,j/2) + image.at<Vec3b>((i+1)/2,(j+1)/2))/2;
	
            newImage.at<Vec3b>(i,j)[0] = (image.at<Vec3b>(i/2,j/2)[0] + image.at<Vec3b>((i+1)/2,(j+1)/2)[0])/2;
            newImage.at<Vec3b>(i,j)[1] = (image.at<Vec3b>(i/2,j/2)[1] + image.at<Vec3b>((i+1)/2,(j+1)/2)[1])/2;	
            newImage.at<Vec3b>(i,j)[2] = (image.at<Vec3b>(i/2,j/2)[2] + image.at<Vec3b>((i+1)/2,(j+1)/2)[2])/2;	
        }
    }
    namedWindow( "Original Images", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Original Images", image );    

    namedWindow( "Zoomed Image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Zoomed Image", newImage );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}