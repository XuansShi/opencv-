//ͼ����ת�;���
#include <opencv2/opencv.hpp>
#include <vector>
#include<iostream>

using namespace cv;
using namespace std;

//��¼��ʼ�ͽ�����ʱ�䣬Ȼ������ɵõ��������е�ʱ�� �ĺ���
void PrintMs(const char* test = " ")
{                     //������������βθ������ֵ
    static long long last = 0;//��¼��һ�μ�¼��ʱ��
    long long cur = getTickCount();//��ȡ��ǰʱ��CPU��������Ȼ�����Ƶ�ʵõ���s

    if (last == 0)
    {
        last = cur;



        return;
    }
    long long ms = 0;
    ms = ((double)(cur - last) / getTickFrequency()) * 1000;//��һ�μ�ȥ�ڶ��ε�ʱ�������������Ƶ�ʣ��ٳ���1000���õ�����ms

    if (*test != 0)//"*test"ָ����ȡ�ַ��������һ���ֽڣ�������ǿ�ջ����ô��һ���ֽھͻ���0
    {
        //������ǿ�ջ���ʹ�ӡ��
        cout << test << "=" << ms << "ms" << endl;

    }
    //��¼��ǰʱ��
    last = getTickCount();

}






int main() 
{
    // ����ͼ��
    Mat src = imread("D:\\ѧϰ����\\�ز�\\�滭\\ݪ5.0\\1.png");//�ֱ���1204x1024 
    Mat rot;
    Mat flipx;
    Mat flipy;
    Mat flipxy;

    cv::rotate(src, rot, ROTATE_90_CLOCKWISE);//˳ʱ����ת90��
    imshow("rot", rot);

    cv::flip(src,flipx,0);//���µߵ�
    imshow("flip1", flipx);

    cv::flip(src, flipy, 1);//���ҵߵ�
    imshow("flipy", flipy);

    cv::flip(src, flipxy, -1);//�������Ҷ��ߵ�
    imshow("flipxy", flipxy);


    waitKey(0);
    return 0;
}


