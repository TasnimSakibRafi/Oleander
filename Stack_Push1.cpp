#include <iostream>
using namespace std;

int s[100];
int topIdx = -1;

bool isEmpty()
{
    return (topIdx == -1);
}

bool isFull()
{
    return (topIdx == 100 - 1);
}

void push(int data)
{
    if (!isFull())
    {
        topIdx++;
        s[topIdx] = data;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "The elements of the stack are: ";
    for (int i = topIdx; i >= 0; i--)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

int main()
{
    int data;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter New Element: ";
        cin >> data;
        push(data);
    }

    display();
}
