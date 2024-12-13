//图像旋转和镜像
#include <opencv2/opencv.hpp>
#include <vector>
#include<iostream>

using namespace cv;
using namespace std;

//记录开始和结束的时间，然后作差即可得到程序运行的时间 的函数
void PrintMs(const char* test = " ")
{                     //括号这里↑给形参赋予个初值
    static long long last = 0;//记录第一次记录的时间
    long long cur = getTickCount();//获取当前时间CPU的跳数，然后除以频率得到秒s

    if (last == 0)
    {
        last = cur;



        return;
    }
    long long ms = 0;
    ms = ((double)(cur - last) / getTickFrequency()) * 1000;//第一次减去第二次的时间的跳数，除以频率，再乘以1000，得到毫秒ms

    if (*test != 0)//"*test"指的是取字符串数组第一个字节，如果它是空栈，那么第一个字节就会是0
    {
        //如果不是空栈，就打印：
        cout << test << "=" << ms << "ms" << endl;

    }
    //记录当前时间
    last = getTickCount();

}






int main() 
{
    // 加载图像
    Mat src = imread("D:\\学习资料\\素材\\绘画\\莳5.0\\1.png");//分辨率1204x1024 
    Mat rot;
    Mat flipx;
    Mat flipy;
    Mat flipxy;

    cv::rotate(src, rot, ROTATE_90_CLOCKWISE);//顺时针旋转90°
    imshow("rot", rot);

    cv::flip(src,flipx,0);//上下颠倒
    imshow("flip1", flipx);

    cv::flip(src, flipy, 1);//左右颠倒
    imshow("flipy", flipy);

    cv::flip(src, flipxy, -1);//上下左右都颠倒
    imshow("flipxy", flipxy);


    waitKey(0);
    return 0;
}


