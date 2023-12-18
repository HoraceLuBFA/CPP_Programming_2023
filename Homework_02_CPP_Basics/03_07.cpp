#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    srand(time(nullptr)); // 初始化随机数生成器
    int playerChoice, computerChoice;
    char playAgain;
    const string choices[3] = {"石头", "剪刀", "布"};

    do {
        cout << "请出手: (0-石头, 1-剪刀, 2-布)";
        cin >> playerChoice;

        if (playerChoice < 0 || playerChoice > 2)
        {
            cout << "输入错误，请重新输入" << endl;
        }
        else
        {
            computerChoice = rand() % 3;
            cout << "你选择了 " << choices[playerChoice] << ", 电脑选择了 " << choices[computerChoice] << endl;

            int result = playerChoice - computerChoice;
            switch (result)
            {
            case 0: // 平局
                cout << "平手！" << endl;
                break;
            case -1:
            case 2: // 玩家赢
                cout << "你赢了！" << endl;
                break;
            case -2:
            case 1: // 电脑赢
                cout << "你输了！" << endl;
                break;
            }
        }

        cout << "再来一局? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
