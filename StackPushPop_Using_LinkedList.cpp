#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;


void push(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head; 
    head = newNode;       
}


int pop()
{
    if (head == NULL)
    {
        cout << "Stack is empty, cannot pop" << endl;
        return -1; 
    }
    Node *temp = head;
    int poppedValue = temp->data;
    head = head->next; 
    delete temp;      
    return poppedValue;
}


void display()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Linked List (Stack): ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " values:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        push(value); 
    }

    display();

 
    cout << "Popped: " << pop() << endl;
    display();

    return 0;
}
