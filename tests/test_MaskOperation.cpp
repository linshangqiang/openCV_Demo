/*
 * 矩阵的掩膜操作 
 */
#include<opencv2/opencv.hpp>
#include<iostream>
#include <math.h>

using namespace cv;
int main(int arge,char **argv)
{
	Mat src, dst;
	src = imread("../../img/lenacolor.png");
	if (src.empty())
	{
		std::cout << "img is empty" << std::endl;
		return -1;
	}
	imshow("src", src);

	//获取图像的宽高  
	int cols = src.cols * src.channels();//3通道
	int offsetx = src.channels();
	int rows = src.rows;
	for (int row = 1; row < rows - 1; row++)
	{	
		for (int col = offsetx; col < cols; col++)
		{
			const uchar* current = src.ptr<uchar>(row);
			const uchar *c

		}
	}
	
	waitKey(0);
	
	return 0;
}