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

//004-数组法
/*
void QuickDemo::pixel_visit_demo(Mat& image)
{
	int w = image.cols;//获取宽度
	int h = image.rows;//获取高度
	int dims = image.channels();//获取通道数（维度）
	                            //灰度图dims=1；彩色图dims=3

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (dims == 1)//灰度图
			{

				int pv = image.at<uchar>(row, col);//灰度图只有单通道，仅获取当前的限速值即可。像素点的每一个限速值都是字节类型<uchar>
					          //at后的括号里
				image.at<uchar>(row, col) = 255 - pv;//如果这里计算结果值超过了2^8-1=255，数据就会溢出



			}
			if (dims == 3)//彩色图像
			{
				Vec3b bgr = image.at<Vec3b>(row,col);//彩色图有3个通道，有int则数据类型为Vec3b，有float则为Vec3f
				//习：每一个像素点可以存储3个值

				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];//第[0]个通道就是第一个通道，也就是Blue的值
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];//Green
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];//Red
			}


		}
	}
	namedWindow("像素读写演示", WINDOW_FREERATIO);
	imshow("像素读写演示", image);
}//该方法遍历数组是基于数组的下标
*/

//004-指针遍历
void QuickDemo::pixel_visit_demo(Mat& image)
{
	int w = image.cols;//获取宽度
	int h = image.rows;//获取高度
	int dims = image.channels();//获取通道数（维度）
	//灰度图dims=1；彩色图dims=3

	for (int row = 0; row < h; row++)
	{
		uchar* current_row = image.ptr<uchar>(row); //获取当前行的指针变量（地址）     //需要uchar类型的指针

		for (int col = 0; col < w; col++)
		{
			if (dims == 1)//灰度图
			{

				int pv = *current_row;//获取该地址对应的值
			
				*current_row++ = 255 - pv;//将指针地址一个个地往后移动（+1）



			}
			if (dims == 3)//彩色图像
			{
				Vec3b bgr = image.at<Vec3b>(row, col);//彩色图有3个通道，有int则数据类型为Vec3b，有float则为Vec3f
				//习：每一个像素点可以存储3个值

				//?:
				*current_row++ = 255 - *current_row;//每复制完一次往后走一个
				*current_row++ = 255 - *current_row;//
				*current_row++ = 255 - *current_row;//
				//雀食快了不少

			}


		}
	}
	namedWindow("像素读写演示", WINDOW_FREERATIO);
	imshow("像素读写演示", image);
}


void QuickDemo::operators_demo(Mat& image)
{
	//像素操作可以加减乘除
	Mat dst;
	dst = image + Scalar(50, 50, 50);// 加和乘 让三通道变亮；减和除 让三通道变暗
	imshow("加法操作", dst);



}


//06↓--------------------------------------------------------------------------------------------------

//加一根滚动条进行调整图像的数据（明暗）
Mat dst, m ,src;
int max_value = 100;
int lightness = 50;

static void on_track(int, void*)
{
	m = Scalar(lightness, lightness, lightness);
	//add(src, m, dst);//变亮
	subtract(src, m, dst);//变暗

	imshow("爱莉希雅3", dst);
}


void  QuickDemo:: tracking_bar_demo(Mat& image)
{
	//调整滚动条数据
	namedWindow("爱莉希雅3", WINDOW_FREERATIO);
	dst = Mat::zeros(image.size(), image.type());
	m = Mat::zeros(image.size(), image.type());
	src = image;
	createTrackbar("Value Bar:", "爱莉希雅3",&lightness, max_value, on_track);
	//createTrackbar函数的传参：
	  //第二个：要调整的图像的窗口
	  //第三个：最小值
	  //第四个：最大值
	  //第五个：函数
	on_track(50, 0);


}
//06↓--------------------------------------------------------------------------------------------------

