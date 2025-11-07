#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
public:
    long long phone[SIZE];
    string name[SIZE];

    HashTable() {
        for(int i = 0; i < SIZE; i++) {
            phone[i] = -1;
            name[i] = "";
        }
    }

    // Linear Probing
    void insertLP(long long p, string n) {
        int index = p % SIZE;
        int i = 0;
        while(phone[(index + i) % SIZE] != -1)
            i++;
        phone[(index + i) % SIZE] = p;
        name[(index + i) % SIZE] = n;
    }

    // Quadratic Probing
    void insertQP(long long p, string n) {
        int index = p % SIZE;
        int i = 0;
        while(phone[(index + i * i) % SIZE] != -1)
            i++;
        phone[(index + i * i) % SIZE] = p;
        name[(index + i * i) % SIZE] = n;
    }

    // Double Hashing
    void insertDH(long long p, string n) {
        int index = p % SIZE;
        int step = 7 - (p % 7);
        int i = 0;
        while(phone[(index + i * step) % SIZE] != -1)
            i++;
        phone[(index + i * step) % SIZE] = p;
        name[(index + i * step) % SIZE] = n;
    }

    // Display Table
    void display() {
        cout << "\nIndex\tPhone\tName\n";
        for(int i = 0; i < SIZE; i++) {
            cout << i << "\t";
            if(phone[i] == -1)
                cout << "-\t-" << endl;
            else
                cout << phone[i] << "\t" << name[i] << endl;
        }
    }

    // Search by phone number
    void search(long long p) {
        for(int i = 0; i < SIZE; i++) {
            if(phone[i] == p) {
                cout << "Record Found -> " << phone[i] << " " << name[i] << endl;
                return;
            }
        }
        cout << "Record Not Found.\n";
    }
};

int main() {
    HashTable h;
    int n, ch;
    long long p;
    string nm;

    do {
        cout << "\n--- Telephone Directory Hash Table ---";
        cout << "\n1) Insert using Linear Probing";
        cout << "\n2) Insert using Quadratic Probing";
        cout << "\n3) Insert using Double Hashing";
        cout << "\n4) Display Hash Table";
        cout << "\n5) Search Phone Number";
        cout << "\n6) Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter Phone and Name: ";
                cin >> p >> nm;
                h.insertLP(p, nm);
                break;

            case 2:
                cout << "Enter Phone and Name: ";
                cin >> p >> nm;
                h.insertQP(p, nm);
                break;

            case 3:
                cout << "Enter Phone and Name: ";
                cin >> p >> nm;
                h.insertDH(p, nm);
                break;

            case 4:
                h.display();
                break;

            case 5:
                cout << "Enter Phone Number to Search: ";
                cin >> p;
                h.search(p);
                break;
        }
    } while(ch != 6);

    return 0;
}
