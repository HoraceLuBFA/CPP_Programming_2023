#include <opencv2/opencv.hpp>

// OpenCV中的预定义类
// OpenCV提供了大量的预定义类，用于各种图像处理和计算机视觉任务。精确地说OpenCV中有多少预定义的类是一个复杂的问题，因为这个数量随着OpenCV版本的不同而变化，并且包含很多专门用途的类。下面列出一些常用和重要的类：

// cv::Mat：表示一个n维的稠密数组，是OpenCV中最基本的数据结构，用于存储图像、矩阵等数据。
// cv::Point、cv::Point2f、cv::Point3f：表示二维和三维点。
// cv::Size：用于表示二维对象（如图像或矩形）的大小。
// cv::Rect：表示矩形区域，用于图像裁剪、对象检测等。
// cv::Scalar：表示四元素的向量，常用于颜色表示（如RGB颜色）。
// cv::VideoCapture：用于视频捕获，可以从视频文件、图像序列或摄像头读取帧。
// cv::VideoWriter：用于视频写入，可以将图像序列编码成视频。
// cv::CascadeClassifier：用于对象检测，特别是用于面部识别和人眼检测。
// cv::Range：用于数组操作中指定行或列的范围。
// 此外，还有许多专用于特定图像处理和计算机视觉任务的类，例如特征检测器类、图像滤波类、几何变换类等。

int main()
{
    // 导入图片
    std::string path = "../Resources/test.png";
    cv::Mat img = cv::imread(path);
    cv::imshow("Image", img);
    while(true)
    {
        // cv::waitKey的返回值是按下键的ASCII码。当参数是0时，它会无限期地等待用户按键，一旦按键发生，它会返回按下键的ASCII码并继续执行程序。如果不关心具体的按键值，通常可以忽略这个返回值。
        int key = cv::waitKey(0);
        if(key == 27) // "Esc"键
        {
            break;
        }
    }    
    
    // 导入视频
    path = "../Resources/test_video.mp4";
    cv::VideoCapture cap(path);
    while(true)
    {
        cap.read(img);
        cv::imshow("Video", img);
        int key = cv::waitKey(20);
        if(key == 27)
        {
            break;
        }
    }

    // 摄像头捕获
    cap.release(); // 释放捕获资源
    cap.open(0); // 指定摄像头ID
    while(true)
    {
        cap.read(img);
        cv::imshow("Image", img);
        int key = cv::waitKey(20);
        if(key == 27)
        {
            break;
        }
    }
    return 0;
}
