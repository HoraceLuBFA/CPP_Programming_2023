#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img;
    std::string path = "../Resources/test.png";
    img = cv::imread(path);
    cv::imshow("Original Image", img);
    cv::waitKey(0);

    // 色彩转换
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY); // 转换颜色
    cv::imshow("Gray Image", imgGray);
    cv::waitKey(0);

    // 边缘检测 Canny
    cv::Mat imgCanny;
    Canny(img, imgCanny, 50, 150);
    cv::imshow("Canny Image", imgCanny);
    cv::waitKey(0);
    
    // 膨胀 Dilate
    cv::Mat imgDia;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    dilate(imgCanny, imgDia, kernel);
    cv::imshow("Dilated Image", imgDia);
    cv::waitKey(0);

    // 侵蚀 Erode
    cv::Mat imgErode;
    cv::erode(imgDia, imgErode, kernel);
    cv::imshow("Eroded Image", imgErode);
    cv::waitKey(0);

    // 改变大小 resize
    cv::Mat imgResize;
    std::cout << img.size() << '\n';
    cv::resize(img, imgResize, cv::Size(), 0.5, 0.5);
    cv::imshow("Resized Image", imgResize);
    cv::waitKey(0);
    
    return 0;
}
