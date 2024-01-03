/*
创建一个 std::list<int>，从标准输入读取一系列整数，并将它们添加到链表中。实现简单功能，从链表中删除第一个和最后一个元素，最后打印剩余的链表。
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> myList;
    int number;
    while (cin >> number) // 接收到非整数值、EOF（如cmd+D）、错误情况时，结束循环
    {
        myList.push_back(number); // 将输入数值依次加入 myList 尾端
    }

    myList.pop_front(); // 移除第一个元素
    myList.pop_back(); // 移除最后一个元素

    for (const auto& num : myList) // range for 输出全部元素
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
