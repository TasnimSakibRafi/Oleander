#include <iostream>
using namespace std;
int maxSize;
int topIdx = -1;
int *stackArr;

bool isFull()
{
    return (topIdx == maxSize);
}

void push(int data)
{
    if (!isFull())
    {
        stackArr[++topIdx] = data;
    }
    else
    {
        cout << "The Stack is Full" << endl;
    }
}

void display()
{
    if (topIdx == -1)
    {
        cout << "Empty";
        return;
    }
    cout << "Element : ";
    for (int i = topIdx; i >= 0; i--)
    {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int value;

    cin >> maxSize;
    stackArr = new int[maxSize];
    cout << endl;
    for (int i = 0; i < maxSize; i++)
    {
        cin >> value;
        push(value);
    }
    display();
    delete[] stackArr;
}
