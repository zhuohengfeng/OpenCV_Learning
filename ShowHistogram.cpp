//
// Created by ryan on 2020/10/18.
//
#include <iostream>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

void showHistoCallback(int state, void* userData) {

}

int main() {
    std::cout << "开始执行显示直方图" << std::endl;

    cv::Mat img = cv::imread("../res/timg.jpeg");

    cv::namedWindow("Show Histogram");

    // 在图像顶部显示叠加信息
    cv::displayOverlay("Show Histogram", "显示直方图", 5000);

    // 创建窗口
    cv::createButton("Show histogram", showHistoCallback, nullptr, cv::QT_CHECKBOX, 0);
    cv::createButton("Show histogram", showHistoCallback, nullptr, cv::QT_RADIOBOX, 0);
    cv::createButton("Show histogram", showHistoCallback, nullptr, cv::QT_PUSH_BUTTON, 0);

    // 显示图片
    cv::imshow("Show Histogram", img);


    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}
