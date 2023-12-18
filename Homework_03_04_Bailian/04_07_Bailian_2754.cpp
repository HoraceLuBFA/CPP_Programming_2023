#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 存放所有的 92 组解
vector<string> solutions;

// 判断在 row 行 col 列放置皇后是否合法
bool isValid(const string& position, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        // 检查列冲突和对角线冲突
        if (position[i] == col || abs(position[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

// 递归函数 + 回溯法，尝试在每一行放置一个皇后，并递归求解剩余的行
void solveQueens(string& position, int row, int n)
{
    if (row == n)
    {
        // 所有行都合法放置了皇后，保存当前解
        solutions.push_back(position);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        // 尝试在当前行的每一列放置皇后
        if (isValid(position, row, col))
        {
            // 如果合法，则在当前位置放置皇后
            position[row] = col;
            // 递归处理下一行
            solveQueens(position, row + 1, n);
            // 回溯：不需要手动移除皇后，下一次循环会覆盖
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string position(8, 0);
    solveQueens(position, 0, 8); // 求出所有 92 组解

    while (n--) {
        int b;
        cin >> b;
        // 使用 range for 循环输出对应编号的解的内容
        for (char c : solutions[b - 1])
        {
            cout << static_cast<int>(c) + 1;
        }
        cout << endl;
    }

    return 0;
}
