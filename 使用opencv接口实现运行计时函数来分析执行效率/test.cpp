//使用opencv接口实现运行记时函数用来分析执行效率
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//记录开始和结束的时间，然后作差即可得到程序运行的时间
void PrintMs(const char* test = " ")
{                     //括号这里↑赋予个初值
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
       cout<<"时间为：" << ms <<"ms" << endl;

   }
   //记录当前时间
   last = getTickCount();

}



int main(int argc , char**argv)
{
  
    Mat mat(3000,4000,CV_8UC3);

    int es = mat.elemSize();
    int size = mat.rows * mat.cols * es;

    PrintMs();
    for (int i = 0; i < size; i+=es)
    {
        mat.data[i] = 255;//B
        mat.data[i+1] = 100;//G
        mat.data[i+2] = 100;//R
    }
    PrintMs("mat.data ms");


    namedWindow("mat",WINDOW_FREERATIO);
    imshow("mat", mat);

    waitKey(0);
    return 0;
} 