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

void in_order(Node* node) {
    if (node == nullptr) return;

    in_order(node->left);
    cout << node->data << " ";
    in_order(node->right);
}

int main() {
    Node* root = nullptr;

   
    root = insert(root, 100);
    root = insert(root, 20);
    root = insert(root, 500);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);

    cout << "In-order Traversal of BST: ";
    in_order(root);
    cout << endl;

    return 0;
}
