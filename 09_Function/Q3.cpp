// Calculate sum of digits of a number 
// The logics is sample number is 145 so the number is divded in each part like 1,4,5 like after that add the number#
#include <iostream>
using namespace std;

int sumDigits(int num) {
    int sum = 0;
    while (num > 0) {
       int lastDi = num % 10; // Add the last digit to sum
        num /= 10;       // Remove the last digit
        sum += lastDi; // Add the last digit to sum
    }
    return sum;
}
int main() {
    cout<<"Sum of digits: " << sumDigits(145) << endl; // Example number 145
}