#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};




Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) return newNode;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}


Node* insertSorted(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};

    
    if (head == nullptr || value < head->data) {
        newNode->next = head;
        return newNode;
    }


    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

   
    newNode->next = current->next;
    current->next = newNode;

    return head;
}






void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}






int main() {
    Node* head = nullptr;
    int n, value, num;

    cout << "Enter number of nodes: ";
    cin >> n;



    cout << "Enter A sorted Array : ";
   
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }



    cout << "Enter Target : ";
    cin >> num;

    head = insertSorted(head, num);

    cout << "Output :  ";
    display(head);

    return 0;
}
