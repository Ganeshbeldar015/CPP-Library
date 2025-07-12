#include <iostream>
using namespace std;

int main()
{

    int n = 4;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << j;
        }
        cout << "\n";
    }
    /*Output
    1234
    1234
    1234
    1234
    */

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << '*';
        }
        cout << "\n";
    }
    /*Output
    ****
    ****
    ****
    ****
    */

    for (int i = 1; i <= n; i++) { // outer loop
        char ch = 'A';
        for (int j = 1; j <= n; j++) { // inner loop
            cout << ch;
            ch = ch + 1; // 65+1=65->'B'
        }
        cout << "\n";
    }
/*Output
ABCD
ABCD
ABCD
ABCD
*/
    int num = 1;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){
            cout<<num<<" ";
            num++;

        }
        cout<<"\n";
/*Output
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16*/
    }
    return 0;
}


