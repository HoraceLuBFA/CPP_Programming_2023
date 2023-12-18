#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for (char & i : str)
        if (i >= 'a' && i <= 'z')
            i -= 32;
        else if (i >= 'A' && i <= 'Z')
            i += 32;
    cout << str << endl;
    return 0;
}