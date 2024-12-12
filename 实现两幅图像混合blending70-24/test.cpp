//ͼ��ߴ����˫�̲߳�ֵ�㷨��������ܲ���
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






int main() 
{
    // ����ͼ��
    Mat src1 = imread("D:\\ѧϰ����\\�ز�\\�滭\\ݪ5.0\\1.png");//�ֱ���1204x1024 
    namedWindow("src1", WINDOW_FREERATIO);
    imshow("src1", src1);
    Mat src2 = imread("D:\\ѧϰ����\\�ز�\\�滭\\ݪ5.0\\2.png");//�ֱ���1204x1024 
    namedWindow("src2", WINDOW_FREERATIO);
    imshow("src2", src2);
    
    Mat dst;
    float a = 0.5;
    addWeighted(src1, a, src2, 1-a, 1, dst);

    namedWindow("blending", WINDOW_FREERATIO);
    imshow("blending", dst);

    

    waitKey(0);
    return 0;
}


