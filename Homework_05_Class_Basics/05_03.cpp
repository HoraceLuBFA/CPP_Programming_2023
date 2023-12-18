#include <iostream>
using namespace std;

// 基类Point类的定义
class Point { 
public: // 公有函数成员
    void initPoint(float x = 0, float y = 0)
    {
        this->x = x;
        this->y = y;
    }
    void move(float offX, float offY)
    {
        x += offX;
        y += offY;
    }
    float getX() const { return x; }
    float getY() const { return y; }

private: // 私有数据成员
    float x, y;
};

// 派生类定义部分
class Rectangle : public Point { 
public: // 新增公有函数成员
    void initRectangle(float x, float y, float w, float h)
    {
        initPoint(x, y); // 调用基类公有成员函数
        this->w = w;
        this->h = h;
    }
    float getH() const { return h; }
    float getW() const { return w; }

private: // 新增私有数据成员
    float w, h;
};

int main()
{
    Rectangle rect; // 定义Rectangle类的对象
    // 设置矩形的数据
    rect.initRectangle(2, 3, 20, 10);
    rect.move(3, 2); // 移动矩形位置
    cout << "The data of rect(x,y,w,h): " << endl;
    // 输出矩形的特征参数
    cout << rect.getX() << ", "
         << rect.getY() << ", "
         << rect.getW() << ", "
         << rect.getH() << endl;
    return 0;
}
