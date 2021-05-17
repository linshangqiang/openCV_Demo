#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
   
    Mat image;

    image = imread("../img/lenacolor.png", 1);
    if (!image.data)
    {
        cout << "No image data" << endl;
        return -1;
    }
    imshow("src",image);
    Mat gray_img;

    cvtColor(image, gray_img, COLOR_BGR2GRAY);
    
    imshow("gray", gray_img);

    waitKey(0);

    return 0;
}