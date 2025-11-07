#include <iostream>
using namespace std;

void selectionSort(float a[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

void bubbleSort(float a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

void displayTopFive(float a[], int n) {
    cout << "\nTop Five Scores:\n";
    int count = min(5, n);
    for(int i = n-1; i >= n-count; i--)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    float per[n];
    cout << "Enter percentages:\n";
    for(int i = 0; i < n; i++)
        cin >> per[i];

    cout << "\nUsing Selection Sort:";
    selectionSort(per, n);
    displayTopFive(per, n);

    cout << "\nUsing Bubble Sort:";
    bubbleSort(per, n);
    displayTopFive(per, n);

    return 0;
}
