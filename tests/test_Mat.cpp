#include<opencv2/opencv.hpp>

#include<iostream>

using namespace cv;

int main(int argc, char** argv) {

	// ����һ��ͼƬ��poyanghu��Сͼ��    
	Mat src = imread("../../img/test.png");
	if (src.empty())
	{
		std::cout << "ͼƬΪ��";
	}
	imshow("src", src);
	
	
	waitKey(0);
	return 0;


}