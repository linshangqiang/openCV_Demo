#include<opencv2/opencv.hpp>

#include<iostream>

using namespace cv;

class imgChange
{
public:
	imgChange() {}

	//转换图像颜色
	void changeImgColor(Mat &src) {
		Mat hls, gray;

		//转成hls
		cvtColor(src, hls, COLOR_BGR2HLS);

		//转成灰度
		cvtColor(src, gray, COLOR_BGR2GRAY);

		// 创建一个名为 "图片"窗口   默认情况下图片窗口不能拖动拉伸，除非第二个参数为WINDOW_NORMAL
		namedWindow("hls");
		namedWindow("gray");

		//显示图片
		imshow("hls", hls);
		imshow("gray", gray);
	};

	void creatMatDemo() {
		//创建空白图像  CV_8UC1:单通道的  CV_8UC3:空白的，3个通道的图像
		Mat blankImg = Mat::zeros(Size(512, 512), CV_8UC3);

		//直接赋值创建
		blankImg = Scalar(127, 127, 127);

		imshow("gray ", blankImg);
		//克隆一个新的
		Mat dts1, dts2;
		dts1 = blankImg.clone();
		blankImg.copyTo(dts2);

		//dts3指向blankImg   实际上就是blankImg
		Mat dts3 = blankImg;

		std::cout << "weight" << blankImg.cols << "height" << blankImg.rows << "channels" << blankImg.channels();
		
	};



};

int main(int argc, char** argv) {

	// 读入一张图片（poyanghu缩小图）    
	Mat src = imread("../../img/test.png");
	if (src.empty())
	{
		std::cout << "图片为空";
	}
	imshow("src", src);
	//以rgb格式载入一张图片
	//Mat rgbImg = imread("C:/Users/Administrator/Desktop/a.jpg", IMREAD_COLOR);

	imgChange m_imgCC;
	m_imgCC.changeImgColor(src);
	m_imgCC.creatMatDemo();

	waitKey(0);
	return 0;


}