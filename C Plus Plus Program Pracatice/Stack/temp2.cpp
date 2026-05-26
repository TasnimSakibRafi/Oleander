#include <iostream>
using namespace std;

int s[100];       // stack array (fixed size)
int topIdx = -1;  // index of top element
int maxSize;      // stack size given by user

bool isFull() {
    return (topIdx == maxSize - 1);
}

void push(int data) {
    if (!isFull()) {
        topIdx++;          // move top index forward
        s[topIdx] = data;  // place new element at that position
    } else {
        cout << "Stack is full" << endl;
    }
}

void display() {
    if (topIdx == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = topIdx; i >= 0; i--) {
        cout << s[i] << " ";
    }
    cout << endl;
}

int main() {
    int value;

    cout << "Enter stack size (max 100): ";
    cin >> maxSize;

    cout << "Enter values (up to " << maxSize << "):" << endl;
    for (int i = 0; i < maxSize; i++) {
        cin >> value;
        push(value);
    }

    display();

    return 0;
}
