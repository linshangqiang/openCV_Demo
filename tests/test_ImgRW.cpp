/*
 * ͼ���дdemo
 */
#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>


using namespace cv;
enum {
	GRAY,
	HSV,
	HLS
};

class CimgRw
{
public:
	typedef std::shared_ptr<CimgRw> Ptr;

public:
	CimgRw() {}

	//ת��ͼ����ɫ
	void changeImgColor(Mat &src,int iColor) {
		Mat dts;
		int i = -1;
		switch (iColor)
		{
		case GRAY:
			cvtColor(src, dts, COLOR_BGR2GRAY);
			imshow("gray", dts);
			break;
		case HLS:
            //ת��hls
			cvtColor(src, dts, COLOR_BGR2HLS);
			imshow("hls", dts);
			break;
		case HSV:
			cvtColor(src, dts, COLOR_BGR2HSV);
			imshow("hsv", dts);
		default:
			break;
		}
		
		//�������������ض���ʽ����Ĳ������룬Ĭ��ֵΪstd::vector<int>  һ�㲻д
		//imwrite("../../img/test_gray.png", dts);
	}; 

	//����һ��Mat����
	void creatMatDemo() {
		//�����հ�ͼ��  CV_8UC1:��ͨ����  CV_8UC3:�հ׵ģ�3��ͨ����ͼ��
		Mat blankImg = Mat::zeros(Size(512, 512), CV_8UC3);//һ����512 ��512*3�Ķ�ά���飬��ʼ������Ԫ��Ϊ0


		//ֱ�Ӹ�ֵ���� ��������blankImgͼƬ��ɻ�ɫ
		blankImg = Scalar(127, 127, 127);

		imshow("gray ", blankImg);
		//��¡һ���µ�
		Mat dts1, dts2;
		dts1 = blankImg.clone();
		blankImg.copyTo(dts2);

		//dts3ָ��blankImg   ʵ���Ͼ���blankImg
		Mat dts3 = blankImg;

		std::cout << "weight" << blankImg.cols << "height" << blankImg.rows << "channels" << blankImg.channels();
		
	};



};

int main(int argc, char** argv) {

	//��ȡһ��ͼƬ
	Mat src = imread("../../img/lenacolor.png");
	if (src.empty())
	{
		std::cout << "ͼƬΪ��";
	}
	// ����һ����Ϊ "hls"����   Ĭ�������ͼƬ���ڲ����϶����죬���ǵڶ�������ΪWINDOW_NORMAL
	namedWindow("src");
	imshow("src", src);
	
	CimgRw::Ptr m_imgCC  = std::make_shared<CimgRw>();

	//תΪhls �� gray
	m_imgCC->changeImgColor(src,GRAY);


	

	waitKey(0);
	return 0;


}