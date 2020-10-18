//
// Created by ryan on 2020/10/18.
//
#include <iostream>
#include <opencv2/core/utility.hpp>
#include <opencv2/core/fast_math.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

cv::Mat img;

void showHistoCallback(int state, void* userData) {
    vector<cv::Mat> bgr;
    cv::split(img, bgr);

    int numbins = 256;

    float range[] = {0, 256};
    const float* histRange = {range};

    cv::Mat b_hist, g_hist, r_hist;
    cv::calcHist(&bgr[0], 1, 0, cv::Mat(), b_hist, 1, &numbins, &histRange);
    cv::calcHist(&bgr[1], 1, 0, cv::Mat(), g_hist, 1, &numbins, &histRange);
    cv::calcHist(&bgr[2], 1, 0, cv::Mat(), r_hist, 1, &numbins, &histRange);

    // 创建灰度图,每个像素20,20,20
    int width = 512;
    int height = 300;
    cv::Mat histImage(height, width, CV_8UC3, cv::Scalar(20, 20, 20));

    cv::normalize(b_hist, b_hist, 0, height, cv::NORM_MINMAX);
    cv::normalize(g_hist, g_hist, 0, height, cv::NORM_MINMAX);
    cv::normalize(r_hist, r_hist, 0, height, cv::NORM_MINMAX);

    int binStep = cvRound((float)width/(float)numbins);
    for (int i = 1; i < numbins; i++) {
        cv::line(histImage, cv::Point(binStep*(i-1), height-cvRound(b_hist.at<float>(i-1))), cv::Point(binStep*(i), height-cvRound(b_hist.at<float>(i))), cv::Scalar(255, 0, 0));
        cv::line(histImage, cv::Point(binStep*(i-1), height-cvRound(g_hist.at<float>(i-1))), cv::Point(binStep*(i), height-cvRound(g_hist.at<float>(i))), cv::Scalar(0, 255, 0));
        cv::line(histImage, cv::Point(binStep*(i-1), height-cvRound(r_hist.at<float>(i-1))), cv::Point(binStep*(i), height-cvRound(r_hist.at<float>(i))), cv::Scalar(0, 0, 255));
    }
    cv::imshow("Histogram", histImage);
}

void equalizeHistoCallback(int state, void* userData) {

}

void lomoCallback(int state, void* userData) {

}

void cartoonCallback(int state, void* userData) {

}

int main() {
    std::cout << "开始执行显示直方图" << std::endl;

    img = cv::imread("../res/timg.jpeg");

    cv::namedWindow("Show Histogram");

    // 在图像顶部显示叠加信息
    cv::displayOverlay("Show Histogram", "显示直方图", 5000);

    // 创建窗口
    cv::createButton("Show histogram", showHistoCallback, nullptr, cv::QT_PUSH_BUTTON, 0);
    cv::createButton("Equalize histogram", equalizeHistoCallback, nullptr, cv::QT_PUSH_BUTTON, 0);
    cv::createButton("Lomography effect", lomoCallback, nullptr, cv::QT_PUSH_BUTTON, 0);
    cv::createButton("Cartoonize effect", cartoonCallback, nullptr, cv::QT_PUSH_BUTTON, 0);

    // 显示图片
    cv::imshow("Show Histogram", img);


    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}
