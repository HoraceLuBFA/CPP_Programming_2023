#include <iostream>
using namespace std;

int main()
{
    double a, b;
    int x = 0;
    cin >> a >> b;
    double result = 1.0;
    while(result <= b)
    {
        result *= a;
        x++;
    }
    x--;
    cout << x;
}