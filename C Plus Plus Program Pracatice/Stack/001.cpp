#include <iostream>
using namespace std;

int stackArr[100];   // array for stack
int topIdx = -1;     // index of top element

bool isFull(int maxSize) {
    return (topIdx == maxSize - 1);
}

void push(int data, int maxSize) {
    if (!isFull(maxSize)) {
        topIdx++;
        stackArr[topIdx] = data;
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
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, value, maxSize;

    cout << "Enter stack size: ";
    cin >> maxSize;

    cout << "Enter number of elements to push: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        push(value, maxSize);
    }

    display();

    return 0;
}