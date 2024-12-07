#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()

{
    //输入图源
    Mat img = imread("D:\\学习资料\\素材\\蛋糕.jpg");

    //缩放
    Mat imgResize;
    //resize(img, imgResize, Size(), 1, 2);//比例因子——第四个参数“1”代表x方向1倍，第五个参数“2”代表y方向2倍
    resize(img, imgResize, Size(100, 300));//第三个参数是代表x、y方向分辨率的数组，此时无法改变比例因子

  
    //显示
    imshow("Image", img);//原图的窗口
    imshow("ImageResieze", imgResize);//缩放图的窗口

    waitKey(0);

    return 0;
}