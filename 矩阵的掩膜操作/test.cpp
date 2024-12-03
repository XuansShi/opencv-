#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc , char**argv)
{
    Mat src, dst;
    src = imread("D:\\学习资料\\素材\\绘画\\花茶.webp");
    if (!src.data)
    {
        cout << "could not load image" << endl;


            return -1;
    }
    namedWindow("input image", WINDOW_AUTOSIZE);
    imshow("input image", src);


    double t = getTickCount();

    //提高图片的对比度——原理法：
   /*
    //获取图像的宽度和高度
      //宽度
    int cols = (src.cols-1) * src.channels();//由于RGB图像有3个通道的值，所以宽度x通道数 = 图像实际宽度
      //高度
    int offsetx = src.channels();
    int rows = src.rows;
    dst = Mat::zeros(src.size(), src.type());

    for (int row = 1;row<rows-1;row++)
//row的初值必须是1↑
    {
      const uchar * previous =  src.ptr<uchar>(row-1);
      const uchar* current = src.ptr<uchar>(row);
      const uchar* next = src.ptr<uchar>(row+1);
      uchar* output = dst.ptr<uchar>(row);

        for (int col = offsetx; col < cols; col++)
        {
            output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));



        }


    }
   
   */
   
   //↑上面这些操作等价于下面两行
    //使用掩膜来提高对比度：
    Mat kernel = (Mat_<char>(3, 3)<< 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src, dst, src.depth(),kernel );
    
    //获取时间
    double timeconsume = (getTickCount() - t) / getTickFrequency();
    cout<<"timeconsum = "  << timeconsume << endl;


    namedWindow("contrast image demo", WINDOW_FREERATIO);
    imshow("contrast image demo", dst);
    waitKey(0);







    return 0;
}