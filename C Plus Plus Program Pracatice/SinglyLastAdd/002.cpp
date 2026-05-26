#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *InsertLast(Node *head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        return newNode;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


void display(Node* head){
    Node* temp = head;
    while (temp != nullptr){
        cout<<temp->data<<"->";
        temp=temp->next ;
    }
    cout<<"Null";
}

int main()
{
    Node* head = new Node {10,nullptr};
    head->next = new Node {20,nullptr};
    head->next->next= new Node {30,nullptr};
    head->next->next->next=new Node {40,nullptr};
    head->next->next->next->next=new Node {50,nullptr};



    head=InsertLast(head,600);
    display(head);
    return 0;
}