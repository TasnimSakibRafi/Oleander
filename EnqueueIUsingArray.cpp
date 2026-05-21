#include <iostream>
using namespace std;

int *queueArr;   
int rear = -1;   
int maxSize;     


bool isFull() {
    return (rear == maxSize - 1);
}



void enqueue(int data) {
    if (!isFull()) {
        queueArr[++rear] = data;  
    } else {
        cout << "Queue is full" << endl;
    }
}



void display() {
    if (rear == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = 0; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}



int main() {
    int value;

    cout << "Enter queue size: ";
    cin >> maxSize;

    queueArr = new int[maxSize];  

    cout << "Enter values :";
    cout<< endl;
    for (int i = 0; i < maxSize; i++) {
        cin >> value;
        enqueue(value);
    }

    display();

    delete[] queueArr;  
    return 0;
}
