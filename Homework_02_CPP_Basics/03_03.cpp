#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;

    // 使用 switch 判断
    switch (num % 7) {
        case 0: cout << "星期日" << endl; break;
        case 1: cout << "星期一" << endl; break;
        case 2: cout << "星期二" << endl; break;
        case 3: cout << "星期三" << endl; break;
        case 4: cout << "星期四" << endl; break;
        case 5: cout << "星期五" << endl; break;
        case 6: cout << "星期六" << endl; break;
    }
    
    // 使用 string 数组
    // string weekdays[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    // cout << weekdays[num % 7] << endl;
    return 0;
}
