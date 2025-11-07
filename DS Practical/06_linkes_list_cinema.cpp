#include <iostream>
using namespace std;

struct Node {
    int seat;
    Node *prev, *next;
};

class Theater {
public:
    Node* head[10];

    Theater() {
        for(int i = 0; i < 10; i++)
            head[i] = NULL;

        for(int r = 0; r < 10; r++)
            for(int s = 1; s <= 7; s++)
                addSeat(r, s);
    }

    void addSeat(int row, int s) { // insert in sorted place
        Node *temp = new Node{s, NULL, NULL};
        if(head[row] == NULL) {
            head[row] = temp;
            return;
        }
        Node *p = head[row], *prev = NULL;
        while(p && p->seat < s) {
            prev = p;
            p = p->next;
        }
        temp->next = p;
        temp->prev = prev;
        if(prev) prev->next = temp;
        else head[row] = temp;
        if(p) p->prev = temp;
    }

    void bookSeat(int row, int s) {
        Node *p = head[row];
        while(p && p->seat != s)
            p = p->next;
        if(!p) {
            cout << "Seat already booked!\n";
            return;
        }
        if(p->prev) p->prev->next = p->next;
        else head[row] = p->next;
        if(p->next) p->next->prev = p->prev;
        delete p;
        cout << "Seat booked.\n";
    }

    void cancelSeat(int row, int s) {
        addSeat(row, s);
        cout << "Booking cancelled.\n";
    }

    void display() {
        for(int r = 0; r < 10; r++) {
            cout << "Row " << r+1 << ": ";
            Node *p = head[r];
            while(p) {
                cout << p->seat << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Theater T;
    int ch, r, s;

    do {
        cout << "\n1) Show Free Seats\n2) Book Seat\n3) Cancel Seat\n4) Exit\nEnter: ";
        cin >> ch;

        if(ch == 1)
            T.display();
        else if(ch == 2) {
            cout << "Enter Row and Seat: ";
            cin >> r >> s;
            T.bookSeat(r-1, s);
        }
        else if(ch == 3) {
            cout << "Enter Row and Seat: ";
            cin >> r >> s;
            T.cancelSeat(r-1, s);
        }
    } while(ch != 4);

    return 0;
}
