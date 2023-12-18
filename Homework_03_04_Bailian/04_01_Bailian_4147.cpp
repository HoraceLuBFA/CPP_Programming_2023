#include <iostream>
using namespace std;

void move(int i, char src, char dest)
{
    cout << i << ":" << src << "->" << dest << '\n';
}

void hanoi(int n, char src, char mid, char dest)
{
    if (n == 1)
    {
        move(1, src, dest);
    }
    else if(n == 2)
    {
        move(1, src, mid);
        move(2, src, dest);
        move(1, mid, dest);
    }
    else
    {
        hanoi(n-1, src, dest, mid);
        move(n, src, dest);
        hanoi(n-1, mid, src, dest);
    }
}

int main()
{
    char tower[3];
    int count;
    cin >> count >> tower[0] >> tower[1] >> tower[2];
    hanoi(count, tower[0], tower[1], tower[2]);
    return 0;
}