#include <iostream>
using namespace std;

int maxSize;
int topIdx = -1;
int *stackArr;

bool isEmpty() { return topIdx == -1; }
bool isFull() { return topIdx == maxSize - 1; }

void push(int val) {
    if (!isFull()) stackArr[++topIdx] = val;
}

int pop() {
    if (!isEmpty()) return stackArr[topIdx--];
    return -1;
}

void insertAtBottom(int val) {
    if (isEmpty()) {
        push(val);
        return;
    }
    int temp = pop();
    insertAtBottom(val);
    push(temp);
}

void reverseStack() {
    if (isEmpty()) return;
    int temp = pop();
    reverseStack();
    insertAtBottom(temp);
}

void display() {
    for (int i = topIdx; i >= 0; i--)
        cout << stackArr[i] << " ";
    cout << endl;
}

int main() {
    cout << "Enter stack size: ";
    cin >> maxSize;
    stackArr = new int[maxSize];

    cout << "Enter elements to push:\n";
    for (int i = 0; i < maxSize; i++) {
        int val;
        cin >> val;
        push(val);
    }
    reverseStack();

    cout << "Reversed stack (top to bottom): ";
    display();

    delete[] stackArr;
    return 0;
}
