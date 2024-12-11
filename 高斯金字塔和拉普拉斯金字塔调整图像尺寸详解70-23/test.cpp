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
    Mat src = imread("D:\\ѧϰ����\\�ز�\\����.jpg");//�ֱ���864x1536  
    imshow("src", src);

    Mat gsrc;
    Mat lsrc;
    // ����
    pyrDown(src, gsrc);//���²�����ͼ���С
    pyrUp(src, lsrc);//���ϲ�����ͼ����

  //ʹ��moveWindow�ƶ����ڵ����Ͻ�
    moveWindow("gsrc", 512, 0);



    imshow("gsrc", gsrc);
    imshow("lsrc", lsrc);



    waitKey(0);
    return 0;
}


