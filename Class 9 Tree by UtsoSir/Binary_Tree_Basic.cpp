#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
public:
    int data;
    Node* left;
    Node* right;
};

struct Node* create_new_node(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
};

void pre_order(Node* node, vector<int> &tree_node)
{
    if(node == nullptr) return;

    tree_node.push_back(node->data);

    pre_order(node->left, tree_node);

    pre_order(node->right, tree_node);
}


/// pre order -- 1, 2, 4, 8, 5, 3, 6, 9, 10, 7

void in_order(Node* node, vector<int> &tree_node)
{
    if(node == nullptr) return;

    in_order(node->left, tree_node);

    tree_node.push_back(node->data);

    in_order(node->right, tree_node);
}

/// in order --- 4, 8, 2, 5, 1, 9, 6, 10, 3, 7


void post_order(Node* node, vector<int> &tree_node)
{
    if(node == nullptr) return;

    post_order(node->left, tree_node);

    post_order(node->right, tree_node);

    tree_node.push_back(node->data);

}

/// post order --- 8, 4, 5, 2, 9, 10, 6, 7, 3, 1

Node* insertNode(Node* root, int new_data)
{
    if( root == nullptr)
    {
        root = create_new_node(new_data);
        return root;
    }

    queue<Node*> queue_node;
    queue_node.push(root);

    while( !queue_node.empty() )
    {
        Node* current = queue_node.front();
        queue_node.pop();

        if(current->left == nullptr)
        {
            current->left = create_new_node(new_data);
            return root;
        }
        else
        {
            queue_node.push(current->left);
        }

        if(current->right == nullptr)
        {
            current->right = create_new_node(new_data);
            return root;
        }
        else
        {
            queue_node.push(current->right);
        }
    }

}
int main()
{
    Node* root = create_new_node(1);

    root->left = create_new_node(2);
    root->right = create_new_node(3);

    root->left->left = create_new_node(4);
    root->left->right = create_new_node(5);

    root->right->left = create_new_node(6);
    root->right->right = create_new_node(7);

    root->left->left->right = create_new_node(8);

    root->right->left->left = create_new_node(9);
    root->right->left->right = create_new_node(10);

    vector<int> pre_order_node_list;
    pre_order(root, pre_order_node_list);

    cout<<"Preorder Traversal: ";
    for(int i=0; i<pre_order_node_list.size(); i++)
    {
        cout<<pre_order_node_list[i]<<" ";
    }
    cout<<endl;

    vector<int> in_order_node_list;
    in_order(root, in_order_node_list);
    cout<<"Inorder Traversal: ";
    for(int i=0; i<in_order_node_list.size(); i++)
    {
        cout<<in_order_node_list[i]<<" ";
    }
    cout<<endl;

    vector<int> post_order_node_list;
    post_order(root, post_order_node_list);
    cout<<"Postorder Traversal: ";
    for(int i=0; i<post_order_node_list.size(); i++)
    {
        cout<<post_order_node_list[i]<<" ";
    }
    cout<<endl;

    root = insertNode(root, 12);

    vector<int> pre_order_node_list_new;
    pre_order(root, pre_order_node_list_new);
    cout<<"Preorder Traversal After Insert: ";
    for(int i=0; i<pre_order_node_list_new.size(); i++)
    {
        cout<<pre_order_node_list_new[i]<<" ";
    }
    cout<<endl;
}
