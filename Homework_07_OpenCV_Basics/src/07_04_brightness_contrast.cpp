#include <opencv2/opencv.hpp>

int main() {
    // 加载原始图像
    cv::Mat img = cv::imread("../Resources/test.png");

    // 创建窗口
    cv::namedWindow("Adjustments", cv::WINDOW_AUTOSIZE);

    // 创建亮度和对比度滑动条
    int brightness = 100; // 初始亮度
    int contrast = 50;    // 初始对比度
    cv::createTrackbar("Brightness", "Adjustments", &brightness, 200);
    cv::createTrackbar("Contrast", "Adjustments", &contrast, 100);

    while (true)
    {
        // 读取滑动条的当前位置
        brightness = cv::getTrackbarPos("Brightness", "Adjustments");
        contrast = cv::getTrackbarPos("Contrast", "Adjustments");

        // 计算新的亮度和对比度
        double alpha = contrast / 50.0; // 对比度系数
        int beta = brightness - 100;    // 亮度增量

        // 调整图像亮度和对比度
        cv::Mat adjusted;
        img.convertTo(adjusted, -1, alpha, beta);

        // 显示调整后的图像
        cv::imshow("Adjustments", adjusted);

        // 检查是否按下 'ESC' 键
        if (cv::waitKey(30) == 27)
        {
            break;
        }
    }

    return 0;
}
