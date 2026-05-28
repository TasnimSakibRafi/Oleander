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
