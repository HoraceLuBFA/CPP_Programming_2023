#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.14159;
class Shape {
public:
    // 计算面积的虚函数
    virtual double calculateArea() const = 0;

    // 计算周长的虚函数
    virtual double calculatePerimeter() const = 0;

    virtual ~Shape();
};

class Circle : public Shape {
private:
    double radius;

public:
    // 构造函数
    Circle(double rad)
        : radius(rad)
    {
    }

    // Override 面积虚函数
    virtual double calculateArea() const override
    {
        return PI * pow(radius, 2);
    }

    // Override 周长虚函数
    virtual double calculatePerimeter() const override
    {
        return 2 * PI * radius;
    }

    virtual ~Circle();
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // 构造函数
    Rectangle(double len, double wid)
        : length(len)
        , width(wid)
    {
    }

    // Override 面积虚函数
    virtual double calculateArea() const override
    {
        return length * width;
    }

    // Override 周长虚函数
    virtual double calculatePerimeter() const override
    {
        return 2 * (length + width);
    }

    virtual ~Rectangle();
};

class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    // 构造函数
    Triangle(double s1, double s2, double s3)
        : side1(s1)
        , side2(s2)
        , side3(s3)
    {
    }

    // Override 面积虚函数
    double calculateArea() const override
    {
        // 海伦公式计算
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Override 周长虚函数
    double calculatePerimeter() const override
    {
        return side1 + side2 + side3;
    }

     virtual ~Triangle();
};

int main()
{
    // 创建不同形状对象
    Circle circle(7.0);
    Rectangle rectangle(4.2, 8.0);
    Triangle triangle(4.0, 4.0, 3.2);

    // 计算面积和周长
    cout << "圆: " << endl;
    cout << "面积: " << circle.calculateArea() << endl;
    cout << "周长: " << circle.calculatePerimeter() << endl;

    cout << "\n矩形: " << endl;
    cout << "面积: " << rectangle.calculateArea() << endl;
    cout << "周长: " << rectangle.calculatePerimeter() << endl;

    cout << "\n三角形: " << endl;
    cout << "面积: " << triangle.calculateArea() << endl;
    cout << "周长: " << triangle.calculatePerimeter() << endl;

    return 0;
}
