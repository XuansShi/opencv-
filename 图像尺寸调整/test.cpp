#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()

{
    //����ͼԴ
    Mat img = imread("D:\\ѧϰ����\\�ز�\\����.jpg");

    //����
    Mat imgResize;
    //resize(img, imgResize, Size(), 1, 2);//�������ӡ������ĸ�������1������x����1���������������2������y����2��
    resize(img, imgResize, Size(100, 300));//�����������Ǵ���x��y����ֱ��ʵ����飬��ʱ�޷��ı��������

  
    //��ʾ
    imshow("Image", img);//ԭͼ�Ĵ���
    imshow("ImageResieze", imgResize);//����ͼ�Ĵ���

    waitKey(0);

    return 0;
}