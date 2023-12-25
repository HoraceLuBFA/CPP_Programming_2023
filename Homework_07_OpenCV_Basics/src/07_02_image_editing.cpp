#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img;
    std::string path = "../Resources/test.png";
    img = cv::imread(path);
    cv::imshow("Original Image", img);
    cv::waitKey(0);

    // 将图像转换为灰度图
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY); // 转换颜色
    cv::imshow("Gray Image", imgGray);
    cv::waitKey(0);

    // 将灰度图像二值化
    cv::Mat imgBinary;
    cv::threshold(img, imgBinary, 128, 255, cv::THRESH_BINARY);
    cv::imshow("Binary Image", imgBinary);
    cv::waitKey(0);

    // 将灰度图像进行高斯模糊处理
    cv::Mat imgBlur;
    cv::GaussianBlur(img, imgBlur, cv::Size(9,9), 5, 0);
    cv::imshow("Gaussian Blur Image", imgBlur);
    cv::waitKey(0);

    return 0;
}
