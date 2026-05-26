#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at the beginning
Node* InsertFirst(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    return newNode; // new head
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Build initial doubly linked list using chaining
    Node* head = new Node{10, nullptr, nullptr};
    head->next = new Node{20, head, nullptr};
    head->next->next = new Node{30, head->next, nullptr};
    head->next->next->next = new Node{40, head->next->next, nullptr};
    head->next->next->next->next = new Node{50, head->next->next->next, nullptr};

    // Insert 5 at the beginning
    head = InsertFirst(head, -500);

    // Display list
    display(head);

    return 0;
}
