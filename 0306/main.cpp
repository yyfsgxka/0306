#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	//练习一
		cv::Mat src_color = imread("C:\\Users\\YangYF\\Desktop\\1.png");
		std::vector<cv::Mat> channels;
		//vector 申明一个保存容器，Mat是容器类型，channels 是名字

		cv::split(src_color, channels);//split函数可以分离图片的三个通道
		cv::Mat B = channels.at(0);//在像素里面以bgr保存
		cv::Mat G = channels.at(1);
		cv::Mat R = channels.at(2);

		cv::imshow("red", R);
		cv::imshow("blue", B);
		cv::imshow("green", G);
		cv::imshow("original Mat", src_color);

		waitKey(0);
	
//练习二
		VideoCapture cap;//实例化一个videocapture类，名称为cap
		cap.open(0);//
		if (!cap.isOpened())
		{
			std::cout << "不可打开视频文件" << std::endl;
			return -1;
		}
		double fps = cap.get(CAP_PROP_FPS);
		std::cout << "fps" << fps << std::endl;
		while (1)
		{
			cv::Mat frame;
			bool rSucess = cap.read(frame);
			if (!rSucess)
			{
				std::cout << "不能从视频中读取帧" << std::endl;
				break;
			}
			else
			{
				cv::imshow("frame ", frame);
			}
			waitKey(30);

		}
		//练习三
	cv::Mat dstMat = imread("C:\\Users\\YangYF\\Desktop\\0.png");
	cv::Point pt;
	pt.x = 100;
	pt.y = 100;
	circle(dstMat, pt, 50, CV_RGB(255, 0, 0), 1, 8, 0);
	waitKey(10);
	return 0;
}


