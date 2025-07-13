#include <iostream>
using namespace std;

int main()
{

    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    // *
    // **
    // ***
    // ****
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << (i + 1);
        }
        cout << "\n";
    }
    char ch = 'A';
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i + 1; j++) {
            cout << ch;
        }
        ch++;
        cout << "\n";
    }
    // A
    // BB
    // CCC
    // DDDD
    for(int i=0;i<n;i++){
        for(int j=1;j<=i+1; j++)
        cout<<j;

    cout<<"\n";
    }
}
