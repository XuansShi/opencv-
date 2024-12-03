#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc , char**argv)
{
    Mat src, dst;
    src = imread("D:\\ѧϰ����\\�ز�\\�滭\\����.webp");
    if (!src.data)
    {
        cout << "could not load image" << endl;


            return -1;
    }
    namedWindow("input image", WINDOW_AUTOSIZE);
    imshow("input image", src);


    double t = getTickCount();

    //���ͼƬ�ĶԱȶȡ���ԭ����
   /*
    //��ȡͼ��Ŀ�Ⱥ͸߶�
      //���
    int cols = (src.cols-1) * src.channels();//����RGBͼ����3��ͨ����ֵ�����Կ��xͨ���� = ͼ��ʵ�ʿ��
      //�߶�
    int offsetx = src.channels();
    int rows = src.rows;
    dst = Mat::zeros(src.size(), src.type());

    for (int row = 1;row<rows-1;row++)
//row�ĳ�ֵ������1��
    {
      const uchar * previous =  src.ptr<uchar>(row-1);
      const uchar* current = src.ptr<uchar>(row);
      const uchar* next = src.ptr<uchar>(row+1);
      uchar* output = dst.ptr<uchar>(row);

        for (int col = offsetx; col < cols; col++)
        {
            output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));



        }


    }
   
   */
   
   //��������Щ�����ȼ�����������
    //ʹ����Ĥ����߶Աȶȣ�
    Mat kernel = (Mat_<char>(3, 3)<< 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src, dst, src.depth(),kernel );
    
    //��ȡʱ��
    double timeconsume = (getTickCount() - t) / getTickFrequency();
    cout<<"timeconsum = "  << timeconsume << endl;


    namedWindow("contrast image demo", WINDOW_FREERATIO);
    imshow("contrast image demo", dst);
    waitKey(0);







    return 0;
}