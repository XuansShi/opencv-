#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// 定义不同颜色的HSV范围，根据实验调整这些范围来准确检测特定颜色
Scalar lower_red(0, 170, 240), upper_red(20, 187, 255);
Scalar lower_green(60, 212, 200), upper_green(74, 240, 220);
Scalar lower_blue(90, 240, 205), upper_blue(103, 255, 210);
Scalar lower_brown(5, 220, 130), upper_brown(15, 239, 136);
Scalar lower_purple(136, 181, 172), upper_purple(138, 190, 181);
Scalar lower_orange(5, 202, 234), upper_orange(13, 220, 241);
Scalar lower_yellow(10, 220, 230), upper_yellow(30, 250, 251);

// 图像预处理函数，增强边缘细节，便于轮廓检测
Mat preprocessImage(Mat& img) {
    Mat hsv, mask, blurred, edges;

    // 将图像从 BGR 转换为 HSV 色彩空间
    cvtColor(img, hsv, COLOR_BGR2HSV);

    // 对图像进行高斯模糊，减少噪点
    GaussianBlur(hsv, blurred, Size(5, 5), 0);

    // 创建掩码图像（无特定范围），用作中间步骤
    inRange(blurred, Scalar(0, 0, 0), Scalar(255, 255, 255), mask);

    // 使用 Canny 算法检测边缘
    Canny(mask, edges, 100, 200);

    // 通过膨胀操作增强边缘
    Mat dilated;
    dilate(edges, dilated, Mat(), Point(-1, -1), 2, 1, 1);

    return dilated;
}

// 检测指定颜色范围的多边形轮廓，并标注每个形状
void detectAndLabelPolygon(Mat& img, Mat& hsv, Scalar lower, Scalar upper, const string& color_name, const Scalar& text_color) {
    // 根据给定的HSV范围生成二值掩码图像，仅保留目标颜色
    Mat mask;
    inRange(hsv, lower, upper, mask);

    // 再次膨胀掩码图像，以增强边界
    Mat dilated;
    dilate(mask, dilated, Mat(), Point(-1, -1), 2, 1, 1);

    // 存储检测到的轮廓
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dilated, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // 存储近似多边形轮廓的点集
    vector<vector<Point>> polygons;

    for (size_t i = 0; i < contours.size(); i++) {
        vector<Point> approx;

        // 使用多边形逼近方法，简化轮廓点集
        approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);

        // 检查近似后的多边形是否至少有3个点，即是否为有效形状
        if (approx.size() >= 3) {
            polygons.push_back(approx);
        }
    }

    // 绘制多边形并标注颜色名称
    for (size_t i = 0; i < polygons.size(); i++) {
        // 绘制每个多边形轮廓，颜色为黑色框线
        polylines(img, polygons[i], true, Scalar(0, 0, 0), 2);

        // 获取轮廓的边界框，并在框的上方写入颜色名称
        Rect bounding_box = boundingRect(polygons[i]);
        putText(img, color_name, Point(bounding_box.x, bounding_box.y - 10), FONT_HERSHEY_SIMPLEX, 0.6, text_color, 2);
    }
}

int main() {
    // 加载目标图片
    Mat img = imread("D:\\学习资料\\素材\\视觉进阶作业1.jpg");

    // 检查图像是否加载成功
    if (img.empty()) {
        cerr << "图像加载失败！" << endl;
        return -1;
    }

    // 将图像从 BGR 转换为 HSV 色彩空间
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    // 对图像中的不同颜色形状进行检测和标注
    detectAndLabelPolygon(img, hsv, lower_red, upper_red, "Red", Scalar(0, 0, 255));
    detectAndLabelPolygon(img, hsv, lower_green, upper_green, "Green", Scalar(0, 255, 0));
    detectAndLabelPolygon(img, hsv, lower_blue, upper_blue, "Blue", Scalar(255, 0, 0));
    detectAndLabelPolygon(img, hsv, lower_brown, upper_brown, "Brown", Scalar(42, 42, 165));
    detectAndLabelPolygon(img, hsv, lower_purple, upper_purple, "Purple", Scalar(128, 0, 128));
    detectAndLabelPolygon(img, hsv, lower_orange, upper_orange, "Orange", Scalar(0, 165, 255));
    detectAndLabelPolygon(img, hsv, lower_yellow, upper_yellow, "Yellow", Scalar(0, 255, 255));

    // 显示处理后的图像
    imshow("Detected Polygons", img);
    waitKey(0);

    return 0;
}
