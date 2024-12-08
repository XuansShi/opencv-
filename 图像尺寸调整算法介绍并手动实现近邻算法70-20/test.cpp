//图像尺寸调整算法介绍并手动实现近邻算法
#include <opencv2/opencv.hpp>
#include <vector>

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

void xresize(Mat& src, Mat&des, Size size)
{

    des.create(size, src.type());
    //映射的原图坐标
    int sx, sy = 0;
    float fx = (float)src.cols / des.cols;//原图的宽 除以 输出图的宽
    float fy = (float)src.rows / des.rows;

    for (int x = 0; x < des.cols; x++)//遍历
    {
        sx = fx * x + 0.5;//算出映射后的x的长度
        for (int y = 0; y < des.rows; y++)
        {

            sy = fy * y + 0.5;//算出映射后的y的长度
            des.at<Vec3b>(y,x) = src.at<Vec3b>(sy,sx);
            //括号中↑ 第一个是行（高度），第二个是列（宽度）
        }

    }


}


int main() {
    // 加载图像
    Mat src = imread("D:\\学习资料\\素材\\蛋糕.jpg");//分辨率864x1536  下面做两次操作，一次放大一次缩小
    namedWindow("src");
    imshow("src", src);

    Mat img256,img1024;
    xresize(src, img256,Size(256,256));
    xresize(src, img1024, Size(1024, 1024));

    imshow("img256", img256);
    imshow("img1024", img1024);



    waitKey(0);
    return 0;
}


