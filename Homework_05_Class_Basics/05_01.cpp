#include <cmath>
#include <iostream>

const double PI = 3.14159;

class Circle {
private:
    double radius;

public:
    // 构建函数
    Circle(double rad)
        : radius(rad)
    {
    }

    // 计算面积的成员函数
    double calculateArea()
    {
        return PI * pow(radius, 2);
    }

    // 计算周长的成员函数
    double calculateCircumference()
    {
        return 2 * PI * radius;
    }
};

int main()
{
    // 创建 Circle 对象
    double radius;
    std::cout << "输入圆的半径: ";
    std::cin >> radius;
    Circle circle(radius);

    // 计算并打印面积
    double area = circle.calculateArea();
    std::cout << "圆的面积: " << area << std::endl;

    // 计算并打印周长
    double circumference = circle.calculateCircumference();
    std::cout << "圆的周长: " << circumference << std::endl;

    return 0;
}
