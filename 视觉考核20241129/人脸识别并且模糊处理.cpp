//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    // 1. 加载级联分类器
//    CascadeClassifier faceCascade;
//    if (!faceCascade.load("D:\\xiazaidedaxue app\\opencv\\haarcascade_frontalface_default.xml"))
//    {
//        cout << "找不到模型文件" << endl;
//        return -1;
//    }
//
//    // 2. 打开摄像头
//    VideoCapture cap(0);
//
//    Mat frame, gray;
//    while (true) {
//        cap >> frame;
//
//
//
//        // 3. 将彩色图像转换为灰度图像
//        cvtColor(frame, gray, COLOR_BGR2GRAY);
//
//
//        // 4. 均衡化直方图，提高图像对比度
//        equalizeHist(gray, gray);
//
//        // 5. 检测人脸
//        vector<Rect> faces;
//        faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));
//
//        // 6. 在每个检测到的人脸周围绘制矩形框
//        for (size_t i = 0; i < faces.size(); i++) {
//            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);
//
//            Mat faceROI = frame(faces[i]);
//            GaussianBlur(faceROI, faceROI, Size(99, 99), 30);
//
//
//        }
//        // 7. 显示图像
//        imshow("人脸检测", frame);
//
//        // 8. 按 'ESC' 键退出
//        if (waitKey(1) == 27)
//        {
//            break;
//        }
//
//
//
//
//    }
//
//    // 9. 释放摄像头并关闭窗口
//    cap.release();
//    destroyAllWindows();
//
//
//    return 0;
//}