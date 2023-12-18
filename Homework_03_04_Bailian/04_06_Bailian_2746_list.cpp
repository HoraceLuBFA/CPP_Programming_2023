#include <iostream>
#include <list>
using namespace std;

// 链表实现
int josephus(int n, int m) {
    list<int> monkeys;
    for (int i = 1; i <= n; ++i) {
        monkeys.push_back(i);
    }

    auto it = monkeys.begin();
    while (monkeys.size() > 1) {
        for (int count = 1; count < m; ++count) {
            ++it;
            if (it == monkeys.end()) {
                it = monkeys.begin();
            }
        }
        it = monkeys.erase(it);
        if (it == monkeys.end()) {
            it = monkeys.begin();
        }
    }
    return *monkeys.begin();
}

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        cout << josephus(n, m) << endl;
    }
    return 0;
}
