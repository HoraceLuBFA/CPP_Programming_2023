#include <iostream>
#include <vector>
using namespace std;

// vector实现
int josephus(int n, int m)
{
    vector<int> monkeys(n); // 创建一个猴子数组
    // 初始化猴子的编号，从1到n
    for (int i = 0; i < n; i++)
    {
        monkeys[i] = i + 1;
    }

    int current = 0; // 当前报数的猴子的索引
    // 当还有多于1只猴子时，继续循环
    while (monkeys.size() > 1)
    {
        // 找到第m只猴子的索引
        current = (current + m - 1) % monkeys.size();
        // 移除报数为m的猴子
        monkeys.erase(monkeys.begin() + current);
    }
    // 返回最后剩下的猴子的编号
    return monkeys[0];
}

int main()
{
    int n, m;
    // 循环读取输入直到n和m都为0
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        cout << josephus(n, m) << endl; // 输出最后猴王的编号
    }
    return 0;
}
