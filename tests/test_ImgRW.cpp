/*
 * ͼ���дdemo
 */
#include<opencv2/opencv.hpp>
#include<iostream>


using namespace cv;

class CimgRw
{
public:
	typedef std::shared_ptr<CimgRw> Ptr;

public:
	CimgRw() {}

	//ת��ͼ����ɫ
	void changeImgColor(Mat &src) {
		Mat hls, gray;

		//ת��hls
		cvtColor(src, hls, COLOR_BGR2HLS);

		//ת�ɻҶ�
		cvtColor(src, gray, COLOR_BGR2GRAY);

		// ����һ����Ϊ "hls"����   Ĭ�������ͼƬ���ڲ����϶����죬���ǵڶ�������ΪWINDOW_NORMAL
		namedWindow("hls");
		//������
		namedWindow("gray", WINDOW_NORMAL);

		//��ʾͼƬ
		imshow("hls", hls);
		imshow("gray", gray);

		//�������������ض���ʽ����Ĳ������룬Ĭ��ֵΪstd::vector<int>  һ�㲻д
		imwrite("../../img/test_gray.png", gray);
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

	// ����һ��ͼƬ��poyanghu��Сͼ��
	if (argc != 2)
	{
		std::cout << "<image path> is empty" << std::endl;
		return -1;
	}
	char* c_path = argv[1];
	

	Mat src = imread(c_path);
	if (src.empty())
	{
		std::cout << "ͼƬΪ��";
	}
	imshow("src", src);
	//��rgb��ʽ����һ��ͼƬ
	//Mat rgbImg = imread("C:/Users/Administrator/Desktop/a.jpg", IMREAD_COLOR);
	

	CimgRw::Ptr m_imgCC  = std::make_shared<CimgRw>();

	//תΪhls �� gray
	m_imgCC->changeImgColor(src);


	m_imgCC->creatMatDemo();

	waitKey(0);
	return 0;


}