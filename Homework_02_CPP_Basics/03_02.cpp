#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    int count = 0;
    cout << "Reversed integer: ";
    do {
        cout << num % 10;
        num /= 10;
        count++;
    } while (num != 0);
    cout << endl;
    cout << "Number of digits: " << count << endl;
    return 0;
}
