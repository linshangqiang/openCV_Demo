#include<opencv2/opencv.hpp>

#include<iostream>

using namespace cv;

int main(int argc, char** argv) {

	// 读入一张图片（poyanghu缩小图）    
	Mat src = imread("../../img/test.png");
	if (src.empty())
	{
		std::cout << "图片为空";
	}
	imshow("src", src);
	
	
	waitKey(0);
	return 0;


}