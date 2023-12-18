#include <iostream>

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3)
        : side1(s1)
        , side2(s2)
        , side3(s3)
    {
    }

    void determineType()
    {
        if (side1 == side2 && side2 == side3) {
            std::cout << "等边三角形" << std::endl;
        } else if (side1 == side2 || side1 == side3 || side2 == side3) {
            std::cout << "等腰三角形" << std::endl;
        } else {
            std::cout << "不规则三角形" << std::endl;
        }
    }
};

int main()
{
    double s1, s2, s3;
    std::cout << "输入三角形的三个边长\n";
    std::cout << "Side1: ";
    std::cin >> s1;
    std::cout << "Side2: ";
    std::cin >> s2;
    std::cout << "Side3: ";
    std::cin >> s3;

    Triangle triangle(s1, s2, s3);

    triangle.determineType();

    return 0;
}
