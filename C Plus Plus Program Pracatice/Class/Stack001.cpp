#include <iostream>
using namespace std;

#define MAX 100   


struct Stack {
    int arr[MAX];
    int top;
};


void init(Stack &s) {
    s.top = -1;
}


void push(Stack &s, int value) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    s.arr[++s.top] = value;
}


int pop(Stack &s) {
    if (s.top == -1) {
        cout << "Stack Underflow!" << endl;
        return -1;  
    }
    return s.arr[s.top--];
}


void display(Stack &s) {
    if (s.top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= s.top; i++) {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;

    int n, value;
    cout << "Enter number of elements to push: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        push(s, value);
    }

    display(s);

    cout << "Popped: " << pop(s) << endl;
    display(s);

    cout << "Popped: " << pop(s) << endl;
    display(s);

    return 0;
}
