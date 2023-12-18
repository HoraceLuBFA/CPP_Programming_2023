#include <iostream>
using namespace std;

// bool数组实现
int josephus(int n, int m) {
    bool monkeys[300] = {false};  // 假定n的最大值为300
    int remaining = n;  // 圈中剩余的猴子数量
    int current = 0;  // 当前报数的猴子索引

    while (remaining > 1) {
        int count = 0;
        while (count < m) {
            // 只在圈内的猴子计数
            if (!monkeys[current]) {
                ++count;
            }
            current = (current + 1) % n;
        }

        // 找到第m个猴子并标记为出圈
        current = (current - 1 + n) % n;
        monkeys[current] = true;
        --remaining;
    }

    // 找到最后剩下的猴子的编号
    for (int i = 0; i < n; ++i) {
        if (!monkeys[i]) {
            return i + 1;  // 编号从1开始
        }
    }
    return -1;  // 不应该到达这里
}

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        cout << josephus(n, m) << endl;
    }
    return 0;
}
