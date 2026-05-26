#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert at the end (returns head)
Node* InsertLast(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        // If list is empty, new node becomes head
        return newNode;
    }



    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;  // head stays the same
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

    // Insert 60 at the end
    head = InsertLast(head, 700);

    cout << "Final list: ";
    display(head);

    return 0;
}
