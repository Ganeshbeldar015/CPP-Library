#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    bool isSwap = false;

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        
    }
    if(!isSwap){
            cout<<"Array is alredy Sorted ";
        }
}

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

    BubbleSort(arr, n);
    PrintArray(arr, n);
}