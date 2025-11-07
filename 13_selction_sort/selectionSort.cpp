#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallestIdx = i;   // index of the smallest element

        // Find the smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallestIdx]) {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
    };
    void PrintArray(int arr[], int n){
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    }
    
    int main(){
    int arr[] = { 4, 1, 5, 2, 3 };
    // int arr[] = { 1,2,3,4,5 };
     int n = 5;

    selectionSort(arr, n);
    PrintArray(arr, n);
}