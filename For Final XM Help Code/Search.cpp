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

bool search_BST(Node* root, int target) {
    Node* current = root;

    while (current != nullptr) {
        if (current->data == target) {
            return true;   
        } else if (target < current->data) {
            current = current->left;  
        } else {
            current = current->right;  
        }
    }
    return false; 
}

int main() {
    Node* root = nullptr;

   
    root = insert(root, 100);
    root = insert(root, 20);
    root = insert(root, 500);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);

    
    int target = 30;
    if (search_BST(root, target)) {
        cout << target << " is in the BST" << endl;
    } else {
        cout << target << " is not in the BST" << endl;
    }

    target = 200;
    if (search_BST(root, target)) {
        cout << target << " is in the BST" << endl;
    } else {
        cout << target << " is not in the BST" << endl;
    }

    return 0;
}
