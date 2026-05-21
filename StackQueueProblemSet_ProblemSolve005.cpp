#include <iostream>
using namespace std;

int maxSize;
int frontIdx = -1, rearIdx = -1;
int *queueArr;

bool isEmpty() {
    return (frontIdx == -1 || frontIdx > rearIdx);
}

bool isFull() {
    return (rearIdx == maxSize - 1);
}

void enqueue(int val) {
    if (isFull()) {
        cout << "Queue is Full\n";
        return;
    }
    if (frontIdx == -1) frontIdx = 0;
    queueArr[++rearIdx] = val;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return -1;
    }
    return queueArr[frontIdx++];
}

void reverseQueue() {
    if (isEmpty()) return;
    int val = dequeue();
    reverseQueue();
    enqueue(val);
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue elements (front to rear): ";
    for (int i = frontIdx; i <= rearIdx; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter queue size: ";
    cin >> maxSize;

    queueArr = new int[maxSize];

    enqueue(1);
    enqueue(2);
    enqueue(3);

    cout << "Original queue: ";
    display();

    reverseQueue();

    cout << "Reversed queue: ";
    display();

    delete[] queueArr;
    return 0;
}
