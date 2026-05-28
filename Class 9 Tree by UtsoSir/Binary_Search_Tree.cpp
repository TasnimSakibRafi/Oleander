#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


Node* insert(Node* root, int new_data)
{
    if(root == nullptr)
    {
        return new Node(new_data);
    }

    if( new_data < root->data )
    {
        root->left = insert(root->left, new_data);
    }
    else
    {
        root->right = insert(root->right, new_data);
    }

    return root;
}


void in_order(Node* node)
{
    if(node == nullptr) return;

    in_order(node->left);

    cout<<node->data<<" ";

    in_order(node->right);
}


/// 1, 3, 4, 6, 7, 8, 10, 13, 14

/// inorder predecessor of 7 is 6
/// inorder successor of 7 is 8
int minimum_value(Node* root)
{
    if(root == nullptr)
    {
        return -1;
    }

    Node* current = root;

    while( current -> left != nullptr)
    {
        current = current->left;
    }
    return current->data;
}



