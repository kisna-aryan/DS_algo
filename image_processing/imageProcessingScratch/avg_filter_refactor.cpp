#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>


using namespace cv;
using namespace std;

vector<vector<int>> filter = {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
};
int filterSize = 3;
int filterOffset =  filterSize / 2;

void applyFilter(Mat& image, vector<vector<int>> filter, int filterSize, int filterOffset, Mat& newImage)
{
    int filterOffsetHalf = filterOffset / 2;
    int filterSizeHalf = filterSize / 2;
    int rows = image.rows;
    int cols = image.cols;
    int channels = image.channels();
    int type = image.type();
    newImage = Mat(rows, cols, type);

    for (int i = filterOffsetHalf; i < rows - filterOffsetHalf; i++)
    {
        for (int j = filterOffsetHalf; j < cols - filterOffsetHalf; j++)
        {
            int sum = 0,sum1=0,sum2=0;
            for (int k = 0; k < filterSize; k++)
            {
                for (int l = 0; l < filterSize; l++)
                {
                    sum += filter[k][l] * image.at<Vec3b>(i + k - filterOffsetHalf, j + l - filterOffsetHalf)[0];	
                    sum1 += filter[k][l] * image.at<Vec3b>(i + k - filterOffsetHalf, j + l - filterOffsetHalf)[1];
                    sum2 += filter[k][l] * image.at<Vec3b>(i + k - filterOffsetHalf, j + l - filterOffsetHalf)[2];
                }
            }
            newImage.at<Vec3b>(i, j)[0] = uint8_t(sum/9);
            newImage.at<Vec3b>(i, j)[1] = uint8_t(sum1/9);
            newImage.at<Vec3b>(i, j)[2] = uint8_t(sum2/9);
        }
    }



}

int main()
{   
    String imageName("../images/image.jpg" ); // by default
    Mat image;
    image = imread( samples::findFile( imageName ), IMREAD_UNCHANGED ); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    int newImageRows  = image.size().height; 
    int newImageCols  = image.size().width; 
    Mat newImage(newImageRows,newImageCols, image.type());

    applyFilter(image, filter, filterSize, filterOffset, newImage);

    namedWindow( "Original Images", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Original Images", image );    

    namedWindow( "Blurred Image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Blurred Image", newImage );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
