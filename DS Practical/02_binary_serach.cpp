#include <iostream>
using namespace std;


bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {       
            return true;
        }
        else if (key > arr[mid]) {   
            low = mid + 1;
        }
        else {                        
            high = mid - 1;
        }
    }
    return false; 
}

int main() {
    int n;
    cout << "Enter number of students attended training: ";
    cin >> n;

    int roll[n];
    cout << "Enter roll numbers in **sorted order**: \n";
    for (int i = 0; i < n; i++) {
        cin >> roll[i];
    }

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;


    if (binarySearch(roll, n, key)) {
        cout << "Student with roll number " << key << " attended the training.\n";
    }
    else {
        cout << "Student with roll number " << key << " did NOT attend the training.\n";
    }

    return 0;
}
