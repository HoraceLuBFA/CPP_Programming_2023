#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n = 0;
    int i = 0;

    // 每次读取的值
    string name;
    int average = 0;
    int vote = 0;
    char isLeader = 'N';
    char isWest = 'N';
    int paperCount = 0;

    // 需要输出的值
    string maxPersonName; // 最大值名字
    int maxPersonSum = 0; // 最大值金额
    int totalSum = 0; // 总金额

    cin >> n;

    for(i = 0; i < n; i++)
    {
        int sum = 0; // 初始化临时总奖学金统计变量
        cin >> name >> average >> vote >> isLeader >> isWest >> paperCount;
        if(average > 80 && paperCount >= 1)
        {
            sum += 8000;
        }
        if(average > 85 && vote > 80)
        {
            sum += 4000;
        }
        if(average > 90)
        {
            sum += 2000;
        }
        if(average > 85 && isWest == 'Y')
        {
            sum += 1000;
        }
        if(vote > 80 && isLeader == 'Y')
        {
            sum += 850;
        }
        if(sum > maxPersonSum) // 更新最大值名字、最大值金额
        {
            maxPersonSum = sum;
            maxPersonName = name;
        }
        totalSum += sum; // 累加总金额
    }
    cout << maxPersonName << endl;
    cout << maxPersonSum << endl;
    cout << totalSum << endl;
    return 0;
}