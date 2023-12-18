#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    // 如果 a 为 0，输出错误信息并返回错误代码
    if (a == 0)
    {
        cerr << "Coefficient 'a' cannot be 0." << endl;
        return -1;
    }

    // 判别式
    double delta = b * b - 4 * a * c;

    if (delta > 0) // 有两个不同实根
    {
        double root1 = (-b + sqrt(delta)) / (2 * a);
        double root2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "Root 1: " << root1 << "\nRoot 2: " << root2 << endl;
    }
    else if (delta == 0) // 有两个相同实根
    {
        double root = -b / (2 * a);
        cout << "Roots are real and the same." << endl;
        cout << "Root: " << root << endl;
    }
    else  // 无实根
    {
        cout << "No real roots." << endl;
    }
    return 0;
}
