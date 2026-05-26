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







// Display function: print the list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Linked List: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout << "NULL" << endl;
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

    return 0;
}
