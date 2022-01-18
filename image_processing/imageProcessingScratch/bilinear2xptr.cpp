#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/core/core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main( int aaish, char** kumar )
{
    String imageName("../images/image.jpg" ); // by default
    cout << kumar[0] << endl;
    if( aaish > 1 )
    {
        imageName = kumar[1];
    }
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
    cout << "Image type: " << image.type() << endl;

    int rows = image.rows;
    int cols = image.cols;

    int newImageRows = image.rows*2;
    int newImageCols = image.cols*2;
    Mat newImage(newImageRows,newImageCols, image.type());
    unsigned char * _ppixel;

    cout << "Image size: " << newImage.size() << endl;
    cout << "Image channels: " << newImage.channels() << endl;
    cout << "Image rows: " << newImage.rows << endl;
    cout << "Image cols: " << newImage.cols << endl;
    _ppixel = image.data;
    unsigned char * _ppixelNew = newImage.data;

    cout << "blue: " << (int)_ppixel[3] << endl;
    cout << "green: " << (int)_ppixel[4] << endl;
    cout << "red: " << (int)_ppixel[5] << endl;

    cout << "bgr :" << image.at<Vec3b>(0,1) << endl;

    for(int i = 0; i < newImageRows; i++)
    {
        for(int j = 0; j < newImageCols; j++)
        {
            int pixidx1 = (j/2)*3 + (i/2)*cols*3;
            int i_next = (i+1)/2;
            int j_next = (j+1)/2;
            int pixidx2 = j_next*3 + i_next*cols*3;

            // newImage.at<Vec3b>(i,j)[0] = (*(_ppixel+pixidx1) + *(_ppixel+pixidx2))/2;
            // newImage.at<Vec3b>(i,j)[1] = (*(_ppixel+pixidx1+1) + *(_ppixel+pixidx2+1))/2;
            // newImage.at<Vec3b>(i,j)[2] = (*(_ppixel+pixidx1+2) + *(_ppixel+pixidx2+2))/2;

            newImage.at<Vec3b>(i,j)[0] = (_ppixel[pixidx1] + _ppixel[pixidx2])/2;
            newImage.at<Vec3b>(i,j)[1] = (_ppixel[pixidx1+1] + _ppixel[pixidx2+1])/2;
            newImage.at<Vec3b>(i,j)[2] = (_ppixel[pixidx1+2] + _ppixel[pixidx2+2])/2;
	
            // newImage.at<Vec3b>(i,j)[0] = (image.at<Vec3b>(i/2,j/2)[0] + image.at<Vec3b>((i+1)/2,(j+1)/2)[0])/2;
            // newImage.at<Vec3b>(i,j)[1] = (image.at<Vec3b>(i/2,j/2)[1] + image.at<Vec3b>((i+1)/2,(j+1)/2)[1])/2;	
            // newImage.at<Vec3b>(i,j)[2] = (image.at<Vec3b>(i/2,j/2)[2] + image.at<Vec3b>((i+1)/2,(j+1)/2)[2])/2;	
        }
    }
    namedWindow( "Original Images", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Original Images", image );    

    namedWindow( "Zoomed Image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Zoomed Image", newImage );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}