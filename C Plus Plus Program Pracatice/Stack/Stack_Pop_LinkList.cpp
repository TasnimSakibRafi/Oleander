#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Push function: insert at the beginning
void push(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head; // link new node to current head
    head = newNode;       // update head
}

// Pop function: remove from the beginning
int pop()
{
    if (head == NULL)
    {
        cout << "Stack is empty, cannot pop" << endl;
        return -1; // sentinel value
    }
    Node *temp = head;
    int poppedValue = temp->data;
    head = head->next; // move head forward
    delete temp;       // free memory
    return poppedValue;
}

// Display function: print the list
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
        push(value); // insert each value at the beginning
    }

    display();

    // Pop one element
    cout << "Popped: " << pop() << endl;
    display();

    return 0;
}
