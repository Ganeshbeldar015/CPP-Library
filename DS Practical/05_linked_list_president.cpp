#include <iostream>
using namespace std;

struct Node {
    string name;
    int prn;
    Node *next;
};

class PinnacleClub {
public:
    Node *head;

    PinnacleClub() {
        head = NULL;
    }

    // Add President (at beginning)
    void addPresident(int prn, string name) {
        Node *temp = new Node{ name, prn, head };
        head = temp;
        cout << "President Added.\n";
    }

    // Add Secretary (at end)
    void addSecretary(int prn, string name) {
        Node *temp = new Node{ name, prn, NULL };

        if (head == NULL) {
            head = temp;
            return;
        }

        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;

        cout << "Secretary Added.\n";
    }

    // Add Member (in the middle)
    void addMember(int prn, string name) {
        Node *temp = new Node{ name, prn, NULL };

        if (head == NULL) {
            cout << "Add President first.\n";
            return;
        }

        Node *p = head;
        while (p->next->next != NULL)
            p = p->next;

        temp->next = p->next;
        p->next = temp;

        cout << "Member Added.\n";
    }

    // Delete President
    void deletePresident() {
        if (head == NULL) return;
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "President Deleted.\n";
    }

    // Delete Secretary
    void deleteSecretary() {
        if (head == NULL) return;

        Node *p = head;
        if (p->next == NULL) {
            delete p;
            head = NULL;
            return;
        }

        while (p->next->next != NULL)
            p = p->next;

        delete p->next;
        p->next = NULL;
        cout << "Secretary Deleted.\n";
    }

    // Delete Member
    void deleteMember(int prn) {
        Node *p = head;
        while (p->next != NULL && p->next->prn != prn)
            p = p->next;

        if (p->next == NULL) {
            cout << "Member not found.\n";
            return;
        }

        Node *temp = p->next;
        p->next = temp->next;
        delete temp;

        cout << "Member Deleted.\n";
    }

    // Display Members
    void display() {
        Node *p = head;
        cout << "\nClub Members:\n";
        while (p != NULL) {
            cout << p->prn << " - " << p->name << endl;
            p = p->next;
        }
    }

    // Count Members
    int count() {
        int c = 0;
        Node *p = head;
        while (p != NULL) {
            c++;
            p = p->next;
        }
        return c;
    }

    // Concatenate two lists
    void concatenate(PinnacleClub &obj) {
        if (head == NULL) {
            head = obj.head;
            return;
        }
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = obj.head;
    }
};

int main() {
    PinnacleClub A, B;

    A.addPresident(1, "Rahul");
    A.addMember(2, "Sneha");
    A.addSecretary(3, "Kiran");

    A.display();
    cout << "\nTotal Members: " << A.count() << endl;

    B.addPresident(4, "Mayur");
    B.addSecretary(5, "Anita");

    cout << "\nAfter Concatenation:\n";
    A.concatenate(B);
    A.display();
}
