
#include <opencv2/opencv.hpp>
#include <quickopencv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    Mat src = imread("D:\\学习资料\\素材\\视觉进阶作业1.jpg");
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    //namedWindow("输入窗口", WINDOW_FREERATIO);
    imshow("输入窗口", src);
    //注意imshow只支持8位的显示和浮点型数据的显示（如果你直接读，没有改什么的话一般就是8位)
  //RGB通道的顺序是： B G R
  //三通道的取值范围：
    // H 0~180
    QuickDemo qd;
    qd.colorSpace_Demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}