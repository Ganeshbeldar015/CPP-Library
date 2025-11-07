#include <iostream>
using namespace std;

// Function for Linear Search
bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {     // Check if element matches
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of students attended training: ";
    cin >> n;

    int roll[n];
    cout << "Enter roll numbers of students:\n";
    for (int i = 0; i < n; i++) {
        cin >> roll[i];
    }

    int key;
    cout << "Enter roll number to search: ";
    cin >> key;

    // Call Linear Search function
    if (linearSearch(roll, n, key)) {
        cout << "Student with roll number " << key << " attended the training.\n";
    } else {
        cout << "Student with roll number " << key << " did NOT attend the training.\n";
    }

    return 0;
}
