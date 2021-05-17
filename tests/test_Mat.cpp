

//Mat对象的创建和赋值

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("../img/test.png");

	// 1.Mat 对象的拷贝
	Mat imgCopy1,imgcCpy2,imgCopy3;
	imgCopy1 = src.clone();  // clone会创建一个新的Mat对象 
	src.copyTo(imgcCpy2);    // copyTo也会创建一个新的Mat对象
	imgCopy3 = src;          //imgCopy3指向src   实际上就是src
	
	//创建一个单通道的512x512的Mat数组  zeros创建的数组所有像素值都是0  
	Mat newMat = Mat::zeros(Size(512, 512), CV_8UC1);
	std::cout << "newMat  :高 = " << newMat.rows << "宽 =" << newMat.cols << "通道数 = " << newMat.channels();

	//将会创建一个三个通道的8x8的Mat数组
	Mat newMat1 = Mat::zeros(Size(8, 8), CV_8UC3);
	std::cout << "newMat1 : 高 = " << newMat1.rows << "宽 =" << newMat1.cols << "通道数 = " << newMat1.channels();

	//只会将每个像素点的第一个通道的值赋值为1
	Mat newMat2 = Mat::ones(Size(8, 8), CV_8UC3);
	std::cout <<"newMat2 :"<<std::endl<< newMat2 << std::endl;

	//也是给每个像素点的第一个通道的值赋值
	newMat1 = 127;
	std::cout << newMat1 << std::endl;

	//给Mat所有像素点所有通道整体赋值为127
	newMat = Scalar(127, 127, 127);
	imshow("127 newMat2", newMat);


	//C++11创建一个Mat数据  3X3的单通道Mat对象，初始化的值都是0
	Mat kernel = (Mat_<char>(3,3)<<0, 0, 0,
								   0, 0, 0,	
								   0, 0, 0);
	
	waitKey(0);
	return 0;


}