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

Node* findInorderSuccessor(Node* current) {
    current = current->right;
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteBST(Node* root, int delvalue) {
    if (root == nullptr) {
        return root;
    }

    if (delvalue < root->data) {
        root->left = deleteBST(root->left, delvalue);
    } else if (delvalue > root->data) {
        root->right = deleteBST(root->right, delvalue);
    } else {
        
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        
        else if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        else if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        else {
            Node* successor = findInorderSuccessor(root);
            root->data = successor->data;
            root->right = deleteBST(root->right, successor->data);
        }
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

    cout << "BST In-order before deletion: ";
    in_order(root);
    cout << endl;

    
    root = deleteBST(root, 20);

    cout << "BST In-order after deleting 20: ";
    in_order(root);
    cout << endl;

    return 0;
}
