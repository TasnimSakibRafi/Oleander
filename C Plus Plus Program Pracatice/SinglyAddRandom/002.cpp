#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *AddAtRandom(Node *head, int value, int pos)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (pos == 1)
    {
        newNode->next = head;
        return head;
    }

    Node *temp = head;
    int count = 1;
    while (temp != nullptr && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        cout << "Position is out of range ";
        delete newNode;
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    head = AddAtRandom(head, 50, 2);
    display(head);

    return 0;
}