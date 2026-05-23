#include <iostream>
using namespace std;

int *queueArr;   
int rear = -1;   
int front = 0;   
int maxSize;     




bool isFull() {
    return (rear == maxSize - 1);
}




bool isEmpty() {
    return (front > rear);
}




void enqueue(int data) {
    if (!isFull()) {
        queueArr[++rear] = data;  
    } else {
        cout << "Queue is full" << endl;
    }
}




void dequeue() {
    if (!isEmpty()) {
        cout << "Dequeued: " ;<< queueArr[front] << endl;
        front++;   
    } else {
        cout << "Queue is empty" << endl;
    }
}




void display() {
    if (isEmpty()) {
        cout << "Queue is empty";
        cout<< endl;
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

    queueArr = new int[maxSize];  

    cout << "Enter values:";
    cout << endl;
    for (int i = 0; i < maxSize; i++) {
        cin >> value;
        enqueue(value);
    }

    display();


    dequeue();

    display();

    delete[] queueArr;  // free memory 
    return 0;
}
