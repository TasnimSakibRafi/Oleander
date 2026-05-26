#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* tos = nullptr; /// head of linked list (top of stack)

Node* create_new_node(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

bool isEmpty() {
    return (tos == nullptr);
}

void push(int data) {
    Node* new_node = create_new_node(data);

    if (tos == nullptr) {
        tos = new_node;
    } else {
        /// insert at first (top of stack)
        new_node->next = tos;
        tos = new_node;
    }
}

int top() {
    /// only return the value of top element. No deletion
    if (tos == nullptr) {
        cout << "Stack is empty" << endl;
        return -1;
    } else {
        return tos->data;
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    } else {
        int topElement = top();
        Node* temp = tos;
        tos = tos->next;
        delete temp;   // free memory
        return topElement;
    }
}

void display() {
    Node* temp = tos;
    if (temp == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "The elements of the stack are: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
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
            cout << "Not valid Option. Choose again" << endl;
        }
    }
}
