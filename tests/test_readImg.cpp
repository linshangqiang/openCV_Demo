#include<opencv2/opencv.hpp>

#include<iostream>

using namespace cv;

class imgChange
{
public:
	imgChange() {}

	//ת��ͼ����ɫ
	void changeImgColor(Mat &src) {
		Mat hls, gray;

		//ת��hls
		cvtColor(src, hls, COLOR_BGR2HLS);

		//ת�ɻҶ�
		cvtColor(src, gray, COLOR_BGR2GRAY);

		// ����һ����Ϊ "ͼƬ"����   Ĭ�������ͼƬ���ڲ����϶����죬���ǵڶ�������ΪWINDOW_NORMAL
		namedWindow("hls");
		namedWindow("gray");

		//��ʾͼƬ
		imshow("hls", hls);
		imshow("gray", gray);
	};

	void creatMatDemo() {
		//�����հ�ͼ��  CV_8UC1:��ͨ����  CV_8UC3:�հ׵ģ�3��ͨ����ͼ��
		Mat blankImg = Mat::zeros(Size(512, 512), CV_8UC3);

		//ֱ�Ӹ�ֵ����
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

	// ����һ��ͼƬ��poyanghu��Сͼ��    
	Mat src = imread("../../img/test.png");
	if (src.empty())
	{
		std::cout << "ͼƬΪ��";
	}
	imshow("src", src);
	//��rgb��ʽ����һ��ͼƬ
	//Mat rgbImg = imread("C:/Users/Administrator/Desktop/a.jpg", IMREAD_COLOR);

	imgChange m_imgCC;
	m_imgCC.changeImgColor(src);
	m_imgCC.creatMatDemo();

	waitKey(0);
	return 0;


}