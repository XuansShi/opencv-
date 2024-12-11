//图像尺寸调整双线程插值算法讲解和性能测试
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






int main() 
{
    // 加载图像
    Mat src = imread("D:\\学习资料\\素材\\蛋糕.jpg");//分辨率864x1536  
    imshow("src", src);

    Mat gsrc;
    Mat lsrc;
    // 采样
    pyrDown(src, gsrc);//向下采样，图像变小
    pyrUp(src, lsrc);//向上采样，图像变大

  //使用moveWindow移动窗口到左上角
    moveWindow("gsrc", 512, 0);



    imshow("gsrc", gsrc);
    imshow("lsrc", lsrc);



    waitKey(0);
    return 0;
}


