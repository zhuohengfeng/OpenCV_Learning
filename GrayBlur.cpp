//
// Created by ryan on 2020/10/18.
//
#include <iostream>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

cv::Mat img;

bool applyGray = false;
bool applyBlur = false;
bool applySobel = false;

void applyFilters() {
    cout << "applyGray=" << applyGray << ", applyBlur" << applyBlur << endl;
    cv::Mat result;

    img.copyTo(result);

    if (applyGray) {
        cv::cvtColor(result, result, cv::COLOR_BGR2GRAY);
    }
    if (applyBlur) {
        cv::blur(result, result, cv::Size(5,5));
    }
    if (applySobel) {
        cv::Sobel(result, result, CV_8U, 1, 1);
    }
    cv::imshow("GrayBlur", result);
}

void blurCallback(int state, void* userData) {
    applyBlur = (bool)state;
    applyFilters();
}

void grayCallback(int state, void* userData) {
    applyGray = true;
    applyFilters();
}

void bgrCallback(int state, void* userData) {
    applyGray = false;
    applyFilters();
}

void sobelCallback(int state, void* userData) {
    applySobel = !applySobel;
    applyFilters();
}

int main() {
    std::cout << "开始执行显示直方图" << std::endl;

    img = cv::imread("../res/timg.jpeg");

    cv::namedWindow("GrayBlur");

    // 在图像顶部显示叠加信息
    cv::displayOverlay("GrayBlur", "请操作...", 5000);

    // 创建窗口
    cv::createButton("Blur", blurCallback, nullptr, cv::QT_CHECKBOX, 0);

    cv::createButton("Gray", grayCallback, nullptr, cv::QT_RADIOBOX, 0);
    cv::createButton("RGB", bgrCallback, nullptr, cv::QT_RADIOBOX, 1);

    cv::createButton("Sobel Filter", sobelCallback, nullptr, cv::QT_PUSH_BUTTON, 0);

    // 显示图片
    cv::imshow("GrayBlur", img);

    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}
