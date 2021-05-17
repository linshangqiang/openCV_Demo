

//Mat����Ĵ����͸�ֵ

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv) {
	Mat src = imread("../img/test.png");

	// 1.Mat ����Ŀ���
	Mat imgCopy1,imgcCpy2,imgCopy3;
	imgCopy1 = src.clone();  // clone�ᴴ��һ���µ�Mat���� 
	src.copyTo(imgcCpy2);    // copyToҲ�ᴴ��һ���µ�Mat����
	imgCopy3 = src;          //imgCopy3ָ��src   ʵ���Ͼ���src
	
	//����һ����ͨ����512x512��Mat����  zeros������������������ֵ����0  
	Mat newMat = Mat::zeros(Size(512, 512), CV_8UC1);
	std::cout << "newMat  :�� = " << newMat.rows << "�� =" << newMat.cols << "ͨ���� = " << newMat.channels();

	//���ᴴ��һ������ͨ����8x8��Mat����
	Mat newMat1 = Mat::zeros(Size(8, 8), CV_8UC3);
	std::cout << "newMat1 : �� = " << newMat1.rows << "�� =" << newMat1.cols << "ͨ���� = " << newMat1.channels();

	//ֻ�Ὣÿ�����ص�ĵ�һ��ͨ����ֵ��ֵΪ1
	Mat newMat2 = Mat::ones(Size(8, 8), CV_8UC3);
	std::cout <<"newMat2 :"<<std::endl<< newMat2 << std::endl;

	//Ҳ�Ǹ�ÿ�����ص�ĵ�һ��ͨ����ֵ��ֵ
	newMat1 = 127;
	std::cout << newMat1 << std::endl;

	//��Mat�������ص�����ͨ�����帳ֵΪ127
	newMat = Scalar(127, 127, 127);
	imshow("127 newMat2", newMat);


	//C++11����һ��Mat����  3X3�ĵ�ͨ��Mat���󣬳�ʼ����ֵ����0
	Mat kernel = (Mat_<char>(3,3)<<0, 0, 0,
								   0, 0, 0,	
								   0, 0, 0);
	
	waitKey(0);
	return 0;


}