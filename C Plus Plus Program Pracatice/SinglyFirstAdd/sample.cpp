#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at the beginning (returns new head)
Node* insertFirst(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    return newNode;   // return updated head
}

// Function to display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create initial list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};
    head->next->next->next->next = new Node{50, nullptr};

    // Insert 5 at the beginning (must assign back to head)
    
    head = insertFirst(head, 5);

    cout << "Final list: ";
    display(head);

    return 0;
}
