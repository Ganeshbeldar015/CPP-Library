// Calculate factorial N

#include <iostream>
using namespace std;

int factN(int n)

{
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
int main()
{

    cout << "Factorial" << " " << factN(4);

    return 0;
}