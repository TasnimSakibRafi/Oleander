#include <iostream>
#include <climits>  
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

bool is_BST_In_Order(Node* root, int& prev) {
    if (root == nullptr) {
        return true;
    }


    if (!is_BST_In_Order(root->left, prev)) {
        return false;
    }

 
    if (root->data <= prev) {
        return false;
    }
    prev = root->data;


    return is_BST_In_Order(root->right, prev);
}

int main() {
    Node* root = nullptr;

  
    root = insert(root, 100);
    root = insert(root, 20);
    root = insert(root, 500);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);

    int prev = INT_MIN;
    if (is_BST_In_Order(root, prev)) {
        cout << "This is a BST" << endl;
    } else {
        cout << "This is not a BST" << endl;
    }

    return 0;
}
