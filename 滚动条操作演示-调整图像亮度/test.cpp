
#include <opencv2/opencv.hpp>
#include <quickopencv.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    Mat src = imread("D:\\ѧϰ����\\�ز�\\�Ӿ�������ҵ1.jpg");
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }

    //�������Ҵ򿪡����봰�ڡ�����
    namedWindow("���봰��", WINDOW_FREERATIO);
    imshow("���봰��", src);
    //ע��imshowֻ֧��8λint����ʾ�͸��������ݵ���ʾ�������ֱ�Ӷ���û�и�ʲô�Ļ�һ�����8λ)
  //RGBͨ����˳���ǣ� B G R
  //��ͨ����ȡֵ��Χ��
    // H 0~180
    QuickDemo qd;

   // qd.colorSpace_Demo(src);

   // qd.pixel_visit_demo(src);//������Ҫ����

   // qd.operators_demo(src);
    qd.tracking_bar_demo(src);
    waitKey(0);
    destroyAllWindows();
    return 0;
}