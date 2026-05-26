#include <iostream>
using namespace std;

int s[100];
int topIdx = -1;




bool isEmpty() {
    return (topIdx == -1);
}






bool isFull() {
    return (topIdx == 100 - 1);
}



//Push zFunction //////////////////

void push(int data) {
    if (!isFull()) {
        topIdx++;
        s[topIdx] = data;
    } else {
        cout << "Stack is full" << endl;
    }
}







//Pop Function //////////////////
int pop() {
    if (!isEmpty()) {
        int data = s[topIdx];
        topIdx--;
        return data;
    } else {
        cout << "Stack is empty" << endl;
        return -1;
    }
}









// Top Finction //////////////////
int top() {
    if (!isEmpty()) {
        return s[topIdx];
    } else {
        cout << "Stack is empty" << endl;
        return -1;
    }
}












// Display Function //////////////////
void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "The elements of the stack are: ";
    for (int i = topIdx; i >= 0; i--) {
        cout << s[i] << " ";
    }
    cout << endl;
}












int main() {
    int option, data;

    while (true) {
        cout << "\n!!! MENU !!!\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Quit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter New Element: ";
            cin >> data;
            push(data);
            break;
        case 2:
            data = pop();
            if (data != -1)
                cout << "Popped element is " << data << endl;
            break;
        case 3:
            data = top();
            if (data != -1)
                cout << "Top element of the stack is " << data << endl;
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            cout << "Not a valid option. Choose again." << endl;
        }
    }
}
