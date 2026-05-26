#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert at a given position (random position)
Node* AddAtRandom(Node* head, int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (pos == 1) {
        // Insert at beginning
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        return newNode; // new head
    }

    Node* temp = head;
    int count = 1;

    // Traverse until the node before the desired position
    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return head;
    }

    // Insert in the middle or end
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
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

    // Insert 600 at position 3
    head = AddAtRandom(head, 600, 1);

    // Display list
    display(head);

    return 0;
}
