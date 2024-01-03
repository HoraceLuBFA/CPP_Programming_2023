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
    // remove_if 是 forward_list 的成员函数，用于移除链表中所有使给定谓词（predicate）返回 true 的元素，谓词是一个可以判断链表中的每个元素是否满足某种条件的函数或函数对象

    // 使用 lambda 表达式定义上述谓词
    // [threshold] 是捕获列表，捕获外部作用域中的 threshold 变量，使得 lambda 表达式可以访问它
    // (const T& value) 是 lambda 表达式的参数列表，它表示每次调用这个 lambda 表达式时都会传入 forward_list 中的一个元素
    // { return value < threshold; } 是 lambda 表达式的主体，它返回一个布尔值，表示当前元素 value 是否小于捕获的 threshold
    
    lst.remove_if([threshold](const T& value) { return value < threshold; });
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
        myList.push_front(number);  // 将读取的整数添加到链表的前端
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
