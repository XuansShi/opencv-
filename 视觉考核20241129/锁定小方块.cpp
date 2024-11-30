

//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main() {
//    // ����Ƶ�ļ�������ͷ
//    VideoCapture cap(0);
//    if (!cap.isOpened()) 
//    {
//        cout << "�򲻿�����ͷ" << endl;
//        return -1;
//    }
//
//    // ����HSV��ɫ��Χ������ɫΪ����
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
//        //BGRתHSV
//        cvtColor(frame, hsv_frame, COLOR_BGR2HSV);
//
//        //������ģ��mask����ѡ����ɫ����
//        inRange(hsv_frame, lower_blue, upper_blue, mask);
//
//        //�������������ƾ��ο�
//        vector<vector<Point>> contours;
//        vector<Vec4i> hierarchy;
//        findContours(mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//
//        // �������������ƾ��ο�
//        for (size_t i = 0; i < contours.size(); i++)
//        {
//            //�������С��
//            if (contourArea(contours[i]) < 500) continue;
//
//            // ��ȡ��Ӿ���
//            Rect waiBox = boundingRect(contours[i]);
//
//            // ��ɸѡ�������λ�ӽ������ε�����
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
//        // ��ʾ���
//        imshow("������С����", frame);
//
//        //���� ESC �����˳�ѭ��
//        if (waitKey(1) == 27)
//        {
//            break;
//        }
//    }
//
//    //�ͷ�����ͷ��Դ���رմ���
//    cap.release();
//    destroyAllWindows();
//
//    return 0;
//}
