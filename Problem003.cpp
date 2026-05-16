#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};




Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) return newNode;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}






Node* reverse(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

   
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }

    
    if (temp != nullptr) {
        head = temp->prev; 
    }
    return head;
}








void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}







int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values : "; 
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }

 

    head = reverse(head);

    cout << "Output : ";
    display(head);

    return 0;
}
