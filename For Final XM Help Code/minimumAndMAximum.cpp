#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int new_data) {
    if (root == nullptr) {
        return new Node(new_data);
    }

    if (new_data < root->data) {
        root->left = insert(root->left, new_data);
    } else {
        root->right = insert(root->right, new_data);
    }

    return root;
}

int minimum_value(Node* root) {
    if (root == nullptr) {
        return -1; 
    }

    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

int maximum_value(Node* root) {
    if (root == nullptr) {
        return -1; 
    }

    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

int main() {
    Node* root = nullptr;

   
    root = insert(root, 100);
    root = insert(root, 20);
    root = insert(root, 500);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);

    cout << "Minimum value in BST: " << minimum_value(root) << endl;
    cout << "Maximum value in BST: " << maximum_value(root) << endl;

    return 0;
}
