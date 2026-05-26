#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at a given position (1-based index)
Node* InsertAtPosition(Node* head, int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (position == 1) {
        // Insert at the beginning
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int count = 1;

    // Traverse until the node before the desired position
    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode; // avoid memory leak
        return head;
    }

    // Insert in the middle
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}











void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Initial list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};
    head->next->next->next->next = new Node{50, nullptr};

    // Insert 600 at position 3
    head = InsertAtPosition(head, 600, 3);

    display(head);

    return 0;
}
