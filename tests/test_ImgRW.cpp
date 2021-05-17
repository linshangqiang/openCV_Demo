/*
 * 图像读写demo
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

	//转换图像颜色
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
            //转成hls
			cvtColor(src, dts, COLOR_BGR2HLS);
			imshow("hls", dts);
			break;
		case HSV:
			cvtColor(src, dts, COLOR_BGR2HSV);
			imshow("hsv", dts);
		default:
			break;
		}
		
		//第三个参数：特定格式保存的参数编码，默认值为std::vector<int>  一般不写
		//imwrite("../../img/test_gray.png", dts);
	}; 

	//创建一个Mat数据
	void creatMatDemo() {
		//创建空白图像  CV_8UC1:单通道的  CV_8UC3:空白的，3个通道的图像
		Mat blankImg = Mat::zeros(Size(512, 512), CV_8UC3);//一个高512 宽512*3的二维数组，初始化所有元素为0


		//直接赋值创建 将创建的blankImg图片变成灰色
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

	//读取一张图片
	Mat src = imread("../../img/lenacolor.png");
	if (src.empty())
	{
		std::cout << "图片为空";
	}
	// 创建一个名为 "hls"窗口   默认情况下图片窗口不能拖动拉伸，除非第二个参数为WINDOW_NORMAL
	namedWindow("src");
	imshow("src", src);
	
	CimgRw::Ptr m_imgCC  = std::make_shared<CimgRw>();

	//转为hls 和 gray
	m_imgCC->changeImgColor(src,GRAY);


	

	waitKey(0);
	return 0;


}