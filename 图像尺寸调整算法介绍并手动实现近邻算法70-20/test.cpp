//ͼ��ߴ�����㷨���ܲ��ֶ�ʵ�ֽ����㷨
#include <opencv2/opencv.hpp>
#include <vector>

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

void xresize(Mat& src, Mat&des, Size size)
{

    des.create(size, src.type());
    //ӳ���ԭͼ����
    int sx, sy = 0;
    float fx = (float)src.cols / des.cols;//ԭͼ�Ŀ� ���� ���ͼ�Ŀ�
    float fy = (float)src.rows / des.rows;

    for (int x = 0; x < des.cols; x++)//����
    {
        sx = fx * x + 0.5;//���ӳ����x�ĳ���
        for (int y = 0; y < des.rows; y++)
        {

            sy = fy * y + 0.5;//���ӳ����y�ĳ���
            des.at<Vec3b>(y,x) = src.at<Vec3b>(sy,sx);
            //�����С� ��һ�����У��߶ȣ����ڶ������У���ȣ�
        }

    }


}


int main() {
    // ����ͼ��
    Mat src = imread("D:\\ѧϰ����\\�ز�\\����.jpg");//�ֱ���864x1536  ���������β�����һ�ηŴ�һ����С
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


