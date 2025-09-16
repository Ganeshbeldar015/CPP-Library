// Array is a collection of elements of the same type placed in contiguous memory locations. It allows you to store multiple values under a single name and access them using an index

#include <iostream>
using namespace std;

int main() {
    // declaring and initializing an array of size 5
    int arr[5] = {2, 4, 8, 12, 16};

    // printing array elements
    for (int i = 0; i < 5; i++) {
        cout << arr[ i] << " ";
    }

    return 0;
} 