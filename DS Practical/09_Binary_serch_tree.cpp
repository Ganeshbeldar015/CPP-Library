#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int value) {
    if(root == NULL) {
        root = new Node{value, NULL, NULL};
        return root;
    }
    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// (ii) Height = longest path
int height(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// (iii) Minimum value = leftmost node
int minValue(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

// (iv) Mirror tree (swap left and right)
void mirror(Node* root) {
    if(root == NULL) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

// (v) Search element
bool search(Node* root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;
    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Display (In-order)
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, value, key;

    cout << "Enter number of initial values: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\n\nEnter value to insert: ";
    cin >> value;
    root = insert(root, value);

    cout << "After Insert (Inorder): ";
    inorder(root);

    cout << "\n\nLongest Path (Height): " << height(root);
    cout << "\nMinimum Value: " << minValue(root);

    mirror(root);
    cout << "\nTree after Mirroring (Inorder): ";
    inorder(root);

    cout << "\n\nEnter value to search: ";
    cin >> key;
    if(search(root, key))
        cout << "Value Found.\n";
    else
        cout << "Value Not Found.\n";

    return 0;
}
