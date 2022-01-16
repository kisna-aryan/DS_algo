#include<iostream>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main() {
   Mat image;//taking an image matrix//
   image = imread("images/flower.png");//loading an image//
   if(image.empty()) {//if image is empty//
      cout<<"Image is empty"<<endl;
      return -1;
   }
   cout << image.size().width << " " << image.size().height << endl;//printing the size of the image//
    cout << image.channels() << endl;//printing the number of channels//

//    int x = image.at<uchar>(10, 29,0);//getting the pixel values//
//    int y = image.at<uchar>(10, 29,1);//getting the pixel values//
//    int z = image.at<uchar>(10, 29,2);//getting the pixel values//
//    cout << "Value of blue channel:" << x << endl;//showing the pixel values//
//    cout << "Value of green channel:" << x << endl;//showing the pixel values//
//    cout << "Value of red channel:" << x << endl;//showing the pixel values//
    Vec3b intensity = image.at<Vec3b>(10, 29);//getting the pixel values//
    Vec3b intensity1 = image.at<Vec3b>(10, 51);//getting the pixel values//
    Vec3b intensity2 = image.at<Vec3b>(10, 73);//getting the pixel values//
    cout << "Value of intensity : " << intensity << endl;//showing the pixel values//
    cout << "Value of intensity1 : " << intensity1 << endl;//showing the pixel values//
    cout << "Value of blue channel:" << intensity + intensity1 << endl;//showing the pixel values//
    cout << image.at<Vec3b>(10, 29) << endl;//getting the pixel values//
   system("pause");//pause the system to visualize the result//
   return 0;
}