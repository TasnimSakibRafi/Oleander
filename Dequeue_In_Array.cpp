#include <iostream>
using namespace std;

int *queueArr;   // dynamic array for queue
int rear = -1;   // rear index (last element)
int front = 0;   // front index (first element)
int maxSize;     // queue size

bool isFull() {
    return (rear == maxSize - 1);
}

bool isEmpty() {
    return (front > rear);
}

void enqueue(int data) {
    if (!isFull()) {
        queueArr[++rear] = data;   // place new element at rear
    } else {
        cout << "Queue is full" << endl;
    }
}

void dequeue() {
    if (!isEmpty()) {
        cout << "Dequeued: " ;<< queueArr[front] << endl;
        front++;   // move front forward
    } else {
        cout << "Queue is empty" << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int value;

    cout << "Enter queue size: ";
    cin >> maxSize;

    queueArr = new int[maxSize];   // allocate array dynamically

    cout << "Enter values:" << endl;
    for (int i = 0; i < maxSize; i++) {
        cin >> value;
        enqueue(value);
    }

    display();

    // Perform only one dequeue
    dequeue();

    display();

    delete[] queueArr;  // free memory
    return 0;
}
