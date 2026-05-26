#include <iostream>
using namespace std;

int *stackArr;
int topIdx = -1;
int maxSize;

bool isFull()
{
    return (topIdx == maxSize - 1);
}

void push(int data)
{
    if (!isFull())
    {
        stackArr[++topIdx] = data;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}

void display()
{
    if (topIdx == -1)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = topIdx; i >= 0; i--)
    {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int value;

    cout << "Enter stack size: ";
    cin >> maxSize;

    stackArr = new int[maxSize];

    cout << "Enter values (up to " << maxSize << "):";
    cout << endl;

    for (int i = 0; i < maxSize; i++)
    {
        cin >> value;
        push(value);
    }

    display();

    delete[] stackArr; // free memory
    return 0;
}
