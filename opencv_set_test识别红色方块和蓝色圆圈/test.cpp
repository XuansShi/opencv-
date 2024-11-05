#include <iostream>
#include <opencv2/opencv.hpp>

// 函数用于检测红色正方形
std::vector<cv::Rect> detectRedSquares(cv::Mat& frame) {
    std::vector<cv::Rect> squares;
    cv::Mat hsv;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    // 定义红色的HSV范围（这里是一个近似范围，可能需要根据实际情况调整）
    cv::Scalar lower_red1(0, 100, 100);
    cv::Scalar upper_red1(10, 255, 255);
    cv::Scalar lower_red2(160, 100, 100);
    cv::Scalar upper_red2(179, 255, 255);

    cv::Mat mask1, mask2;
    cv::inRange(hsv, lower_red1, upper_red1, mask1);
    cv::inRange(hsv, lower_red2, upper_red2, mask2);
    cv::Mat redMask = mask1 + mask2;

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(redMask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); i++) {
        double perimeter = cv::arcLength(contours[i], true);
        std::vector<cv::Point> approx;
        cv::approxPolyDP(contours[i], approx, 0.04 * perimeter, true);
        if (approx.size() == 4) {
            cv::Rect rect = cv::boundingRect(approx);
            squares.push_back(rect);
        }
    }
    return squares;
}

// 函数用于检测蓝色圆形
std::vector<cv::Vec3f> detectBlueCircles(cv::Mat& frame) {
    std::vector<cv::Vec3f> circles;
    cv::Mat hsv;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    // 定义蓝色的HSV范围（近似范围，可能需要调整）
    cv::Scalar lower_blue(100, 100, 100);
    cv::Scalar upper_blue(130, 255, 255);
    cv::Mat blueMask;
    cv::inRange(hsv, lower_blue, upper_blue, blueMask);

    cv::GaussianBlur(blueMask, blueMask, cv::Size(9, 9), 2, 2);
    cv::HoughCircles(blueMask, circles, cv::HOUGH_GRADIENT, 1, blueMask.rows / 8, 100, 30, 0, 0);
    return circles;
}

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        cap.read(frame);

        // 检测红色正方形
        std::vector<cv::Rect> redSquares = detectRedSquares(frame);
        for (size_t i = 0; i < redSquares.size(); i++) {
            cv::rectangle(frame, redSquares[i], cv::Scalar(0, 0, 255), 2);
        }

        // 检测蓝色圆形
        std::vector<cv::Vec3f> blueCircles = detectBlueCircles(frame);
        for (size_t i = 0; i < blueCircles.size(); i++) {
            cv::Point center(cvRound(blueCircles[i][0]), cvRound(blueCircles[i][1]));
            int radius = cvRound(blueCircles[i][2]);
            cv::circle(frame, center, radius, cv::Scalar(255, 0, 0), 2);
        }

        cv::imshow("Frame", frame);

        char c = (char)cv::waitKey(30);
        if (c == 27)
            break;
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}