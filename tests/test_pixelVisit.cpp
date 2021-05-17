

//Mat对象的创建和赋值

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv) {
	Mat src;
	src = imread("../../img/face1.jpg");
	if (src.empty())
	{
		std::cout << "img is empty" << std::endl;
		return -1;
	}
	imshow("src", src);

	//获取图像的宽高  
	int iCols = src.cols ;
	int iChannel = src.channels();
	int iRows = src.rows;
	for (int row = 1; row < iRows ; row++)
	{
		uchar* current = src.ptr<uchar>(row);
		for (int col = 0; col <iCols ; col++)
		{
			if (iChannel == 1 ){//灰度图像
				int pv = *current;
				*current++ = 255 - pv;
			}
			if (iChannel == 3) {
				*current++ = 255 - *current;
				*current++ = 255 - *current;
				*current++ = 255 - *current;
			}
		}
	}
	imshow("dts", src);
	waitKey(0);
	return 0;


}