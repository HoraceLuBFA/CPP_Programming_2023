/*
创建一个 std::vector<int> 容器，从标准输入读取一系列整数。编写一个函数 uniqueSort，实现去除容器中的重复元素，并按升序排序，最后按顺序打印处理后的容器元素。
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void uniqueSort(vector<int>& vec)
{
    sort(vec.begin(), vec.end()); // 升序排序
    
    // std::unique 函数用于移除容器中连续重复的元素，但不实际删除元素。其原理是重新排列元素，将不重复的元素放到向量的开始部分，将重复元素移动到末尾，并返回指向第一个重复元素的迭代器。在使用 unique 前一般需要对容器排序。
    auto last = unique(vec.begin(), vec.end());

    // 在 unique 函数之后通常配合 erase 方法来实际删除多余的元素。
    vec.erase(last, vec.end());
}

int main()
{
    vector<int> myVector;
    int num;
    while (cin >> num)
    {
        myVector.push_back(num);
    }

    uniqueSort(myVector); // 去除容器中的重复元素，并按升序排序

    for (const auto& elem : myVector) // range for 按顺序打印
    {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
