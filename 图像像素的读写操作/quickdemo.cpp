
#include <quickopencv.h>
#include <opencv2/dnn.hpp>

using namespace cv;
using namespace std;

//void QuickDemo::colorSpace_Demo(Mat& image) {
//	Mat gray, hsv;
//	cvtColor(image, hsv, COLOR_BGR2HSV);//RGB转HSV
//	// H 0 ~ 180, S, V 
//	cvtColor(image, gray, COLOR_BGR2GRAY);//RGB转灰度
//	imshow("HSV", hsv);//显示那张转了HSV的图
//	imshow("灰度", gray);//显示那张转了灰度的图
//
//	imwrite("D:/hsv.png", hsv);//保存图像的函数，有三个参数： 
//	//第一个参数是保存路径以及文件名字
//	//第二个参数是对象的名字
//	imwrite("D:/gray.png", gray);
//}


void QuickDemo::mat_creation_demo() {
	// Mat m1, m2;
	// m1 = image.clone();
	// image.copyTo(m2);

	// �����հ�ͼ��
	Mat m3 = Mat::zeros(Size(8, 8), CV_8UC3);
	m3 = Scalar(0, 0, 255);
	std::cout << "width: " << m3.cols << " height: " << m3.rows << " channels: "<<m3.channels()<< std::endl;
	// std::cout << m3 << std::endl;

	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(0, 255, 255);
	imshow("ͼ��", m3);
	imshow("ͼ��4", m4);
}


void QuickDemo::pixel_visit_demo(Mat& image)
{
	int w = image.cols;//获取宽度
	int h = image.rows;//获取高度
	int dims = image.channels();//获取通道数

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (dims == 1)//灰度图
			{

				int pv = image.at<uchar>(row, col);
					          //at后的括号里

			}
			if (dims == 3)//彩色图像
			{
				image.at < Vec3b > endl;


			}


		}
	}
}