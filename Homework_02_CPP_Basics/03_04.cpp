#include <iostream>
using namespace std;

int main()
{
    const int HEIGHT = 7; // 行数（常数）
    int row = 1; // 列数
    while (row <= HEIGHT) // 对每列进行操作
    {
        // 打印空格
        int space = HEIGHT - row;
        while (space > 0)
        {
            cout << " ";
            space--;
        }
        // 打印星号
        int star = 1;
        while (star <= (2 * row - 1))
        {
            cout << "*";
            star++;
        }
        cout << endl;
        row++;
    }
    return 0;
}
