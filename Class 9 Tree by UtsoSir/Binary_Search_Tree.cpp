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


bool search_BST(Node* root, int target)
{
    bool flag = false;
    Node* current = root;

    while( current !=nullptr )
    {
        if( current->data == target)
        {
            flag = true;
            break;
        }
        else if( target < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current -> right;
        }
    }
    return flag;
}


int maximum_value(Node* root)
{
    if(root == nullptr)
    {
        return -1;
    }

    Node* current = root;

    while( current -> right != nullptr)
    {
        current = current->right;
    }
    return current->data;
}

bool is_BST_In_Order(Node* root, int& prev)
{
    Node* node = root;
    if (!node)
    {
        return true;
    }

    if ( !is_BST_In_Order(node->left, prev))
    {
        return false;
    }

    if( node->data <= prev )
    {
        return false;
    }

    prev = node->data;

    if ( !is_BST_In_Order(node->right, prev))
    {
        return false;
    }
    else
    {
        return true;
    }
}


Node* findInorderSuccessor(Node* current)
{
    current = current->right;

    while(current != nullptr && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node* deleteBST(Node* root, int delvalue)
{
    if(root == nullptr)
    {
        return root;
    }

    if( delvalue < root->data )
    {
        root->left = deleteBST(root->left, delvalue);
    }
    else if( delvalue > root->data)
    {
        root->right = deleteBST((root->right, delvalue));
    }
    else
    {
        //case with zero
        if( root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // case with one child - left
        else if( root->left != nullptr && root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // case with one child - right
        else if( root->left == nullptr && root->right != nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // case with two child - Find inorder successor
        else
        {
            Node* successor = findInorderSuccessor(root);
            root->data = successor->data;
            root->right = deleteBST(root->right, successor->data);
            return root;
        }
    }
}

int main()
{
    Node* root = new Node(100);

//    root->left = new Node(11);
//    root->right = new Node(9);
//
//    root->left->left = new Node(7);
//
//    root->right->left = new Node(15);
//    root->right->right = new Node(8);
//
//    int prev = INT_MIN;
//    if (is_BST_In_Order(root, prev))
//    {
//        cout<<"This is a BST"<<endl;
//    }
//    else{
//        cout<<"This is not a BST"<<endl;
//    }

    root = insert(root, 20);
    root = insert(root, 500);
    root = insert(root, 10);
    root = insert(root, 30);

    in_order(root);
    cout<<endl;

    root = insert(root, 40);

    in_order(root);
    cout<<endl;

    cout<<"Minimum value in BST : "<<minimum_value(root)<<endl;
    cout<<"Maximum value in BST : "<<maximum_value(root)<<endl;

    int prev = INT_MIN;
    if (is_BST_In_Order(root, prev))
    {
        cout<<"This is a BST"<<endl;
    }
    else{
        cout<<"This is not a BST"<<endl;
    }

    if ( search_BST(root, 30) )
    {
        cout<<"30 is in the BST"<<endl;
    }
    else{
        cout<<"30 is not in the BST"<<endl;
    }

/// 100, 20, 500, 50, 30, 40, 15, 200

}

                100
            20       500
           15  50   200
              30
                40



