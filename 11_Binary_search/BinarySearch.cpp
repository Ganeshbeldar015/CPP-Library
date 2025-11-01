#include <iostream>
#include <vector>
using namespace std;

// create a function
int BinarySearch(vector<int> arr, int tar)
{
    int st = 0, end = arr.size() - 1;

    while (st <= end) {
        int mid = (st + end) / 2;

        if (tar > arr[mid]) {
            st = mid + 1;
        } else if (tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid;
        }
    }
}

int main(){
    vector<int> arr1 = {-1,2,5,6,9,10,15,16,18,24,26,35,95 };
    int tar1 = 15;
    cout<<BinarySearch(arr1,tar1)<<endl;
}