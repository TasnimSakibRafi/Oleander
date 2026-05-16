#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

// Insert keeping ascending order
void insertSorted(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != NULL && current->next->data < value)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

// Print linked list
void printList() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete middle node
void deleteMiddle() {
    if (head == NULL || head->next == NULL) {
        cout << "List too short to delete middle." << endl;
        return;
    }

    // Find length
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2; // middle index
    temp = head;
    Node *prev = NULL;

    for (int i = 0; i < mid; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
}

int main() {
    int n, val;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertSorted(val);
    }

    cout << "Linked List (sorted): ";
    printList();

    deleteMiddle();

    cout << "After deletion: ";
    printList();

    return 0;
}
