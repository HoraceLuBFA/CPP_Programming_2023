/*
创建一个 std::forward_list<int> 单向链表，从标准输入读取一系列整数。编写一个函数模板 filterList（利用template关键字），它接受 forward_list 和一个阈值作为参数，并移除所有小于此阈值的元素，最后打印处理后的列表。
*/

#include <forward_list>
#include <iostream>
using namespace std;

// 过滤单向链表的模板函数 filterList
template <typename T>
void filterList(forward_list<T>& lst, T threshold)
{
    // 使用迭代器遍历，并手动删除不满足条件的元素
    auto it = lst.before_begin(); // 指向链表第一个元素之前位置的迭代器
    auto next_it = lst.begin(); // 指向链表第一个元素的迭代器
    while (next_it != lst.end()) // 遍历链表直到末尾
    {
        if (*next_it < threshold) // // 如果当前元素小于阈值，则移除它
        {
            next_it = lst.erase_after(it); // // 移除元素，并更新 next_it 指向下一个元素
        }
        else // // 如果当前元素不小于阈值
        {
            it = next_it; // 更新 it 指向当前元素
            ++next_it; // 移动 next_it 指向下一个元素
        }
    }
}

int main()
{
    forward_list<int> myList; // 创建一个存储 int 类型的 forward_list
    int number;
    while (cin >> number) // 读取整数并添加到 forward_list
    {
        if(number == -1) // 输入-1截止
        {
            break;
        }
        myList.push_front(number); // 将读取的整数添加到链表的前端
    }

    int threshold;
    cout << "Enter threshold: ";
    cin >> threshold; // 输入阈值

    filterList(myList, threshold); // 调用 filterList 函数过滤链表

    myList.reverse();  // 反转链表
    for (const auto& num : myList) // range for 遍历打印所有元素
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
