#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* create_new_node(int new_data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = new_data;
    temp->next = NULL;
    return temp;
}

void print_linked_list(struct Node* head)
{
    if(head == NULL)
    {
        printf("Empty Linked List");
    }
    else
    {
        struct Node* temp = head;

        while(temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}



struct Node* insert_at_first(int new_data, struct Node* head)
{
    if(head == NULL)
    {
        head = create_new_node(new_data);
    }
    else
    {
        struct Node* new_node = create_new_node(new_data);
        new_node->next = head;
        head = new_node;
    }
    return head;
}


struct Node* insert_at_last(int new_data, struct Node* head)
{
    if(head == NULL)
    {
        head = create_new_node(new_data);
    }
    else
    {
        struct Node* temp = head;
        while( temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = create_new_node(new_data);
    }

    return head;
}

struct Node* insert_at_middle(int position, int new_data, struct Node* head)
{
    if(head == NULL && position != 0)
    {
        printf("Empty Linked List");
    }
    else if(head == NULL && position == 0)
    {
        head = create_new_node(new_data);
    }
    else
    {
        int i = 0;
        struct Node* temp = head;

        while( i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        struct Node* new_node = create_new_node(new_data);

        new_node -> next = temp->next;
        temp->next = new_node;
    }

    return head;
}

struct Node* insert_after_particular_element(int new_data, int target, struct Node* head)
{
    struct Node* temp = head;

    while(temp->data != target && temp != NULL)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Target %d is not Found in Linked List\n", target);
    }
    else
    {
        struct Node* new_node = create_new_node(new_data);

        new_node -> next = temp->next;
        temp->next = new_node;
    }
    return head;
}





