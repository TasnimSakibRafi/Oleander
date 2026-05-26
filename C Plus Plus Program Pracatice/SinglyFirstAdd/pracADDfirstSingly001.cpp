# include <iostream>
using namespace std ;
struct Node {
    int data;
    Node* next ;
};

Node* InsertFirst(Node* head,int value){
    Node* newNode  = new Node();
    newNode -> data = value;
    newNode -> next= head ;
    return newNode ;

}

void display(Node* head){
    Node* temp = head ;
    while (temp != nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}




int main(){

Node* head=new Node {10,nullptr};
head->next=new Node {20,nullptr}; 
head->next->next=new Node {30,nullptr};
head->next->next->next=new Node {40,nullptr};
head ->next->next->next->next=new Node {50,nullptr};

head= InsertFirst(head,5);
display(head);

return 0;
}