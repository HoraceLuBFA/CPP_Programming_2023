/*
使用 std::deque<int> 实现一个简单的队列，从标准输入循环读取并接收 push、pop、print 命令，如“”push 5”将 5 入队，“pop” 出队一个元素，“print” 打印队列中的所有元素。自定义退出命令。
*/

#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    deque<int> myDeque;
    string command;
    int number;

    while (cin >> command)
    {
        if (command == "push") // 数字推入deque后端
        {
            cin >> number;
            myDeque.push_back(number);
            cout << "Pushed " << number << " to the back." << endl;
        }
        else if (command == "pop") // 输出deque前端数字并弹出
        {
            if (!myDeque.empty())
            {
                number = myDeque.front(); // 读取front数字
                myDeque.pop_front(); // 弹出front数字（无返回值）
                cout << "Popped " << number << " in the front." << endl;
            }
        }
        else if (command == "print") // 打印deque内所有数字
        {
            for (const auto& num : myDeque)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        else if (command == "quit") // 退出
        {
            cout << "Quitting..." << endl;
            return 0;
        }
    }
    return 0;
}
