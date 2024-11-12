//������Դ��https://blog.csdn.net/zhuoqingjoking97298/article/details/122762445?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522F2D130AB-D928-40A2-AEE9-1CA906449517%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=F2D130AB-D928-40A2-AEE9-1CA906449517&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~hot_rank-4-122762445-null-null.142^v100^pc_search_result_base1&utm_term=%E8%BE%B9%E7%BC%98%E6%A3%80%E6%B5%8Bopencv&spm=1018.2226.3001.4187

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // Reading image��ȡͼ��
    Mat img = imread("D:\\ѧϰ����\\�ز�\\2024082902062237-1536x864.jpg", 3);

    // Display original imageչʾ��ʼͼ��
    namedWindow("original Image", WINDOW_FREERATIO);
    imshow("original Image", img);


    // Convert to graycsale
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);


    //Blur the image for better edge detection�Ա߽總��������ͨ��ģ��������ƽ��
    Mat img_blur;
    GaussianBlur(img_gray, img_blur, Size(3, 3), 0);

    //Sobel edge detection  Sobel��Ե���
    Mat sobelx, sobely, sobelxy;
    Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);//dx=1,dy=0����ʾ����x�����ϵ�һ�׵�����
    Sobel(img_blur, sobely, CV_64F, 0, 1, 5);//dx=0,dy=1����ʾ����x�����ϵ�һ�׵�����
    Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);//dx=1,dy=1����ô����ͼ�������������ϵ�һ�׵���Sobelͼ��
    // Display Sobel edge detection images  չʾSobel��Ե�����ͼ��
    namedWindow("Sobel X", WINDOW_FREERATIO);
    namedWindow("Sobel Y", WINDOW_FREERATIO);
    namedWindow("Sobel XY using Sobel() function", WINDOW_FREERATIO);
    imshow("Sobel X", sobelx);
    //waitKey(0);
    imshow("Sobel Y", sobely);
    //waitKey(0);
    imshow("Sobel XY using Sobel() function", sobelxy);
    //waitKey(0);




    // Canny edge detection  Canny��Ե���
    Mat edges;
    Canny(img_blur, edges, 100, 200, 3, false);

    // Display canny edge detected image չʾCanny��Ե�����ͼ��
    namedWindow("Canny edge detection", WINDOW_FREERATIO);
    imshow("Canny edge detection", edges);
    waitKey(0);

    destroyAllWindows();
    return 0;
}