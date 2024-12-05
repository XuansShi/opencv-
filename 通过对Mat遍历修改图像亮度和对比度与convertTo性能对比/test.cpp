//ͨ����Mat�����޸�ͼ�����ȺͶԱȶ���convertTo���ܶԱ�
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



//�ֶ���д����ʵ�����ȵ���
void ChangeGain(Mat &src,Mat&des,float a, int b)//��3��������Ӧ�Աȶȣ���4��������Ӧ����
{
    //�㷨��ʽ��g(r,c) = a*f(r,c)+b
    des.create(src.rows, src.cols, src.type());//����ԭͼ�ĳ���������
    for (int r = 0; r < src.rows; r++)
    {
        for (int c = 0; c < src.cols; c++)
        {
            for (int i = 0; i < 3; i++)
            {

                des.at<Vec3b>(r, c)[i] = saturate_cast<uchar>(a * src.at<Vec3b>(r, c)[i]+b);//ʹ��saturate���������������255��Ϊ255��С��0��Ϊ0

            }



        }


    }



}


int main() {
    // ����ͼ��
    Mat src = imread("D:\\ѧϰ����\\�ز�\\����.jpg");
    // ���ͼ���Ƿ���سɹ�
    if (src.empty())
    {
        cout << "Error: Image not found!" << endl;
        return -1;
    }
    imshow("src", src);

    Mat des;
    PrintMs("");
    ChangeGain(src, des,2.0,50);
    PrintMs("ChangeGain");
    //ע���Աȶȵ�����ʽ�����ȵ�����ʽ����output = alpha * input + beta
    imshow("des",des);



    //ʹ��opencv�Դ��ĺ�����
    Mat des2;
    src.convertTo(des2,-1,2.0,50);//�ڶ��������������������Ϊ��ԭͼ����һ��
    PrintMs("ConvertTo");
    imshow("des2", des2);




    waitKey(0);
    return 0;
}


