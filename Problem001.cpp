#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insertEnd(Node *head, int value)
{
    Node *newNode = new Node{value, nullptr};
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

Node *deleteEven(Node *head)
{
    while (head != nullptr && head->data % 2 == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    Node *current = head;
    while (current != nullptr && current->next != nullptr)
    {
        if (current->next->data % 2 == 0)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        head = insertEnd(head, value);
    }

    head = deleteEven(head);

    cout << "Output : ";
    display(head);

    return 0;
}
