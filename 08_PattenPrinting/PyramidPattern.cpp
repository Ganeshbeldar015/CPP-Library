#include <iostream>
using namespace std;

int main()
{

    int n = 4;

    for (int i = 0; i < n; i++) {
        // spaces

        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // num1
        for (int j = 1; j <= i + 1; j++) {
            cout << j;
        }
        // num2
        for (int j = 1; j < i + 1; j++) {
            cout << j;
        }
        cout << "\n";
    }
    //  1
    // 121
    // 12312
    // 1234123
}