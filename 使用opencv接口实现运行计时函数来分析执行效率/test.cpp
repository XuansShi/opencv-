//ʹ��opencv�ӿ�ʵ�����м�ʱ������������ִ��Ч��
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

//��¼��ʼ�ͽ�����ʱ�䣬Ȼ������ɵõ��������е�ʱ��
void PrintMs(const char* test = " ")
{                     //����������������ֵ
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
       cout<<"ʱ��Ϊ��" << ms <<"ms" << endl;

   }
   //��¼��ǰʱ��
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