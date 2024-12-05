//通过对Mat遍历修改图像亮度和对比度与convertTo性能对比
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



//手动编写函数实现亮度调整
void ChangeGain(Mat &src,Mat&des,float a, int b)//第3个参数对应对比度，第4个参数对应亮度
{
    //算法公式：g(r,c) = a*f(r,c)+b
    des.create(src.rows, src.cols, src.type());//创建原图的长、宽、类型
    for (int r = 0; r < src.rows; r++)
    {
        for (int c = 0; c < src.cols; c++)
        {
            for (int i = 0; i < 3; i++)
            {

                des.at<Vec3b>(r, c)[i] = saturate_cast<uchar>(a * src.at<Vec3b>(r, c)[i]+b);//使用saturate函数防溢出，超出255的为255，小于0的为0

            }



        }


    }



}


int main() {
    // 加载图像
    Mat src = imread("D:\\学习资料\\素材\\蛋糕.jpg");
    // 检查图像是否加载成功
    if (src.empty())
    {
        cout << "Error: Image not found!" << endl;
        return -1;
    }
    imshow("src", src);

    Mat des;
    PrintMs("");
    ChangeGain(src, des,2.0,50);
    PrintMs("ChangeGain");
    //注：对比度调整公式（亮度调整公式）：output = alpha * input + beta
    imshow("des",des);



    //使用opencv自带的函数：
    Mat des2;
    src.convertTo(des2,-1,2.0,50);//第二个参数如果传负数，意为与原图类型一致
    PrintMs("ConvertTo");
    imshow("des2", des2);




    waitKey(0);
    return 0;
}


