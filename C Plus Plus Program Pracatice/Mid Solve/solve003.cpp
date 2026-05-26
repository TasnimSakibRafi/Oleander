#include <iostream>
using namespace std;

int maxSize;
int top1 = -1, top2 = -1;
int *stack1, *stack2;

bool isEmpty() {
    return (top1 == -1 && top2 == -1);
}

bool isFull() {
    return (top1 == maxSize - 1);
}

void push1(int val) {
    if (!isFull()) stack1[++top1] = val;
}

int pop1() {
    if (top1 != -1) return stack1[top1--];
    return -1;
}

void push2(int val) {
    stack2[++top2] = val;
}

int pop2() {
    if (top2 != -1) return stack2[top2--];
    return -1;
}

void enqueue(int val) {
    if (isFull()) {
        cout << "Queue is Full\n";
        return;
    }
    push1(val);
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return -1;
    }

    // Move all elements from stack1 to stack2
    while (top1 != -1) {
        push2(pop1());
    }

    // Pop from stack2 (front of queue)
    int front = pop2();

    // Move elements back to stack1
    while (top2 != -1) {
        push1(pop2());
    }

    return front;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue elements (front to rear): ";
    for (int i = 0; i <= top1; i++) {
        cout << stack1[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter queue size: ";
    cin >> maxSize;

    stack1 = new int[maxSize];
    stack2 = new int[maxSize];

    enqueue(1);
    enqueue(2);

    cout << "Dequeued: " << dequeue() << endl;
    display();

    cout << "Is Empty: " << (isEmpty() ? "True" : "False") << endl;

    delete[] stack1;
    delete[] stack2;
    return 0;
}
