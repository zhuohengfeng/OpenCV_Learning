#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main() {
    std::cout << "开始执行" << std::endl;

    cv::Mat frame;
    cv::VideoCapture videoCapture;

    videoCapture.open(0);
    if (!videoCapture.isOpened()) {
        std::cout << "打开摄像头错误" << std::endl;
        return 0;
    }

    cv::namedWindow("HelloWorld");

    while(cv::waitKeyEx(30) != 27) { // ESC
        videoCapture >> frame;
        if (frame.empty()) {
            break;
        }
        cv::imshow("HelloWorld", frame);
    }


    cv::destroyAllWindows();

    return 0;
}