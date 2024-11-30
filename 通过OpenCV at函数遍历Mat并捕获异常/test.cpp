//ʹ��opencv�ӿ�ʵ�����м�ʱ������������ִ��Ч��
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

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



int main(int argc, char** argv)
{

    Mat mat(3000, 4000, CV_8UC3);

    int es = mat.elemSize();//��ɫ��С�ֽ�����BGRΪ3
    int size = mat.rows * mat.cols * es;

    PrintMs();
    //�������޸�������OpenCV Matͼ��ռ�
    for (int i = 0; i < size; i += es)
    {
        mat.data[i] = 255;//B
        mat.data[i + 1] = 100;//G
        mat.data[i + 2] = 100;//R
    }
    PrintMs("mat.data ms");


    //������������OpenCV Mat�ռ�
    for (int row = 0; row < mat.rows; row++)
    {
        for (int col = 0; col < mat.cols; col++)
        {
            (&mat.data[row * mat.step])[col * es] = 0;//B
            (&mat.data[row * mat.step])[col * es + 1] = 0;//G
            (&mat.data[row * mat.step])[col * es + 2] = 255;//R
        }


    }
    PrintMs("mat.step ms");

    //ʹ��ptr����Mat
    for (int row = 0; row < mat.rows; row++)
    {
        for (int col = 0; col < mat.cols; col++)
        {
            //����forѭ��������������ݣ���ȡ�к��С�

            Vec3b* c = mat.ptr<Vec3b>(row, col);
            c->val[0] = 0;//B
            c->val[1] = 255;//G
            c->val[2] = 0;//R
        }
    }
    PrintMs("mat.ptr ms");


     



    //ʹ��at����
      //�ô���ֻʹ�����õķ�ʽ���з��ʣ������������𲻴�
    for (int row = 0; row < mat.rows; row++)
    {
        for (int col = 0; col < mat.cols; col++)
        {
            //����forѭ��������������ݣ���ȡ�к��С�
           Vec3b &m =   //����һ�����ñ���
                      mat.at<Vec3b>(row, col);//���ģ���Ա������Ȼ��ָ���������ͣ�����д�к���
           m[0] = 100;
           m[1] = 100;
           m[2] = 100;
  

        }
    }
    PrintMs("mat.at");




    //ʹ��try������쳣
    try
    {
        for (int row = 0; row < mat.rows; row++)
        {
            for (int col = 0; col < mat.cols; col++)
            {
                //����forѭ��������������ݣ���ȡ�к��С�
                Vec3b& m =   //����һ�����ñ���
                    mat.at<Vec3b>(row, col);//���ģ���Ա������Ȼ��ָ���������ͣ�����д�к���
                m[0] = 100;
                m[1] = 100;
                m[2] = 100;


            }
        }
    
    
    
    }
    catch (Exception &ex)//try��ִ����䣻����һ���쳣��
    {

        cout << ex.what() << endl;

    }
    PrintMs("mat.at");





    namedWindow("mat", WINDOW_FREERATIO);
    imshow("mat", mat);

    waitKey(0);
    return 0;
}


//���е�ʱ����ʹ��Release������Ŀ�����С