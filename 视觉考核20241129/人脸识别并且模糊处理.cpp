//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    // 1. ���ؼ���������
//    CascadeClassifier faceCascade;
//    if (!faceCascade.load("D:\\xiazaidedaxue app\\opencv\\haarcascade_frontalface_default.xml"))
//    {
//        cout << "�Ҳ���ģ���ļ�" << endl;
//        return -1;
//    }
//
//    // 2. ������ͷ
//    VideoCapture cap(0);
//
//    Mat frame, gray;
//    while (true) {
//        cap >> frame;
//
//
//
//        // 3. ����ɫͼ��ת��Ϊ�Ҷ�ͼ��
//        cvtColor(frame, gray, COLOR_BGR2GRAY);
//
//
//        // 4. ���⻯ֱ��ͼ�����ͼ��Աȶ�
//        equalizeHist(gray, gray);
//
//        // 5. �������
//        vector<Rect> faces;
//        faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));
//
//        // 6. ��ÿ����⵽��������Χ���ƾ��ο�
//        for (size_t i = 0; i < faces.size(); i++) {
//            rectangle(frame, faces[i], Scalar(0, 255, 0), 2);
//
//            Mat faceROI = frame(faces[i]);
//            GaussianBlur(faceROI, faceROI, Size(99, 99), 30);
//
//
//        }
//        // 7. ��ʾͼ��
//        imshow("�������", frame);
//
//        // 8. �� 'ESC' ���˳�
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
//    // 9. �ͷ�����ͷ���رմ���
//    cap.release();
//    destroyAllWindows();
//
//
//    return 0;
//}