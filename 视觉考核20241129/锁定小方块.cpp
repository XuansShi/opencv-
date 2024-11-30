

//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main() {
//    // 打开视频文件或摄像头
//    VideoCapture cap(0);
//    if (!cap.isOpened()) 
//    {
//        cout << "打不开摄像头" << endl;
//        return -1;
//    }
//
//    // 定义HSV颜色范围（以蓝色为例）
//    Scalar lower_blue(100, 150, 50);
//    Scalar upper_blue(140, 255, 255);
//
//    Mat frame, hsv_frame, mask, result;
//
//    while (true)
//    {
//
//        cap >> frame;
//
//        if (frame.empty()) 
//        {
//            break;
//        }
//
//        //BGR转HSV
//        cvtColor(frame, hsv_frame, COLOR_BGR2HSV);
//
//        //生成掩模（mask），选择蓝色区域
//        inRange(hsv_frame, lower_blue, upper_blue, mask);
//
//        //查找轮廓，绘制矩形框
//        vector<vector<Point>> contours;
//        vector<Vec4i> hierarchy;
//        findContours(mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//
//        // 遍历轮廓，绘制矩形框
//        for (size_t i = 0; i < contours.size(); i++)
//        {
//            //跳过面积小的
//            if (contourArea(contours[i]) < 500) continue;
//
//            // 获取外接矩形
//            Rect waiBox = boundingRect(contours[i]);
//
//            // 仅筛选出正方形或接近正方形的区域
//            if (abs(waiBox.width - waiBox.height) < waiBox.width * 0.3)
//            {
//                rectangle(frame, waiBox, Scalar(0, 255, 0), 2);  
//            }
//
//
//
//        }
//
//
//        // 显示结果
//        imshow("检测出的小方块", frame);
//
//        //按下 ESC 键，退出循环
//        if (waitKey(1) == 27)
//        {
//            break;
//        }
//    }
//
//    //释放摄像头资源并关闭窗口
//    cap.release();
//    destroyAllWindows();
//
//    return 0;
//}
