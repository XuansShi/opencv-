#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// ���岻ͬ��ɫ��HSV��Χ������ʵ�������Щ��Χ��׼ȷ����ض���ɫ
Scalar lower_red(0, 170, 240), upper_red(20, 187, 255);
Scalar lower_green(60, 212, 200), upper_green(74, 240, 220);
Scalar lower_blue(90, 240, 205), upper_blue(103, 255, 210);
Scalar lower_brown(5, 220, 130), upper_brown(15, 239, 136);
Scalar lower_purple(136, 181, 172), upper_purple(138, 190, 181);
Scalar lower_orange(5, 202, 234), upper_orange(13, 220, 241);
Scalar lower_yellow(10, 220, 230), upper_yellow(30, 250, 251);

// ͼ��Ԥ����������ǿ��Եϸ�ڣ������������
Mat preprocessImage(Mat& img) {
    Mat hsv, mask, blurred, edges;

    // ��ͼ��� BGR ת��Ϊ HSV ɫ�ʿռ�
    cvtColor(img, hsv, COLOR_BGR2HSV);

    // ��ͼ����и�˹ģ�����������
    GaussianBlur(hsv, blurred, Size(5, 5), 0);

    // ��������ͼ�����ض���Χ���������м䲽��
    inRange(blurred, Scalar(0, 0, 0), Scalar(255, 255, 255), mask);

    // ʹ�� Canny �㷨����Ե
    Canny(mask, edges, 100, 200);

    // ͨ�����Ͳ�����ǿ��Ե
    Mat dilated;
    dilate(edges, dilated, Mat(), Point(-1, -1), 2, 1, 1);

    return dilated;
}

// ���ָ����ɫ��Χ�Ķ��������������עÿ����״
void detectAndLabelPolygon(Mat& img, Mat& hsv, Scalar lower, Scalar upper, const string& color_name, const Scalar& text_color) {
    // ���ݸ�����HSV��Χ���ɶ�ֵ����ͼ�񣬽�����Ŀ����ɫ
    Mat mask;
    inRange(hsv, lower, upper, mask);

    // �ٴ���������ͼ������ǿ�߽�
    Mat dilated;
    dilate(mask, dilated, Mat(), Point(-1, -1), 2, 1, 1);

    // �洢��⵽������
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dilated, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // �洢���ƶ���������ĵ㼯
    vector<vector<Point>> polygons;

    for (size_t i = 0; i < contours.size(); i++) {
        vector<Point> approx;

        // ʹ�ö���αƽ��������������㼯
        approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);

        // �����ƺ�Ķ�����Ƿ�������3���㣬���Ƿ�Ϊ��Ч��״
        if (approx.size() >= 3) {
            polygons.push_back(approx);
        }
    }

    // ���ƶ���β���ע��ɫ����
    for (size_t i = 0; i < polygons.size(); i++) {
        // ����ÿ���������������ɫΪ��ɫ����
        polylines(img, polygons[i], true, Scalar(0, 0, 0), 2);

        // ��ȡ�����ı߽�򣬲��ڿ���Ϸ�д����ɫ����
        Rect bounding_box = boundingRect(polygons[i]);
        putText(img, color_name, Point(bounding_box.x, bounding_box.y - 10), FONT_HERSHEY_SIMPLEX, 0.6, text_color, 2);
    }
}

int main() {
    // ����Ŀ��ͼƬ
    Mat img = imread("D:\\ѧϰ����\\�ز�\\�Ӿ�������ҵ1.jpg");

    // ���ͼ���Ƿ���سɹ�
    if (img.empty()) {
        cerr << "ͼ�����ʧ�ܣ�" << endl;
        return -1;
    }

    // ��ͼ��� BGR ת��Ϊ HSV ɫ�ʿռ�
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    // ��ͼ���еĲ�ͬ��ɫ��״���м��ͱ�ע
    detectAndLabelPolygon(img, hsv, lower_red, upper_red, "Red", Scalar(0, 0, 255));
    detectAndLabelPolygon(img, hsv, lower_green, upper_green, "Green", Scalar(0, 255, 0));
    detectAndLabelPolygon(img, hsv, lower_blue, upper_blue, "Blue", Scalar(255, 0, 0));
    detectAndLabelPolygon(img, hsv, lower_brown, upper_brown, "Brown", Scalar(42, 42, 165));
    detectAndLabelPolygon(img, hsv, lower_purple, upper_purple, "Purple", Scalar(128, 0, 128));
    detectAndLabelPolygon(img, hsv, lower_orange, upper_orange, "Orange", Scalar(0, 165, 255));
    detectAndLabelPolygon(img, hsv, lower_yellow, upper_yellow, "Yellow", Scalar(0, 255, 255));

    // ��ʾ������ͼ��
    imshow("Detected Polygons", img);
    waitKey(0);

    return 0;
}
