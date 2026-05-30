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


struct Node* delete_particular_element(int target, struct Node* head)
{
    struct Node* temp = head;

    /// head value == target
    if(head->data == target)
    {
        struct Node* deleteNode = head;
        head = head->next;
        free(deleteNode);
        return head;
    }

    /// goes to the element before the target
    while(temp->next != NULL && temp->next->data != target )
    {
        temp = temp->next;
    }

    /// reached last element but not found target
    if(temp->next == NULL && temp->data != target)
    {
        printf("Target is not in the list. Cannot Not be Deleleted\n");
    }
    /// last element is the target element. Just Delete it
    else if(temp->next == NULL && temp->data == target)
    {
        free(temp);
    }
    else
    {
        /// store node to be delete (temp->next->value == target)
        /// set temp->next =  the next element of the node to be deleted
        /// free deletedNode
        struct Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        free(deleteNode);
    }
    return head;
}

int size_of_linked_list(struct Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        int count=0;
        struct Node* temp = head;

        while(temp != NULL)
        {
            count = count + 1;
            temp = temp->next;
        }
        return count;
    }
}

int middle_element_of_linked_list(struct Node* head)
{
    int size = size_of_linked_list(head);

    int i=0;
    struct Node* temp = head;
    while( i < size/2)
    {
        temp = temp -> next;
        i++;
    }
    return temp->data;
}



int count_occurrences(int target, struct Node* head)
{
    struct Node* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        if(temp->data == target)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}
int main()
{
    struct Node* head = NULL;

    head = insert_at_first(10, head);

    head = insert_at_last(20, head);

    head = insert_at_last(30, head);

//    printf("%d->", head->data);
//    printf("%d->", head->next->data);
//    printf("%d", head->next->next->data);

    print_linked_list(head);

    head = insert_at_first(40, head);
    head = insert_at_first(50, head);
    print_linked_list(head);

    printf("Enter 60 at position 2\n");
    head = insert_at_middle(2,60, head);
    print_linked_list(head);

    printf("Enter 70 after element 20\n");
    head = insert_after_particular_element(70,20,head);
    print_linked_list(head);

    printf("Delete Node 20\n");
    head = delete_particular_element(20,head);
    print_linked_list(head);

    printf("Delete Node 30\n");
    head = delete_particular_element(30,head);
    print_linked_list(head);

    printf("Delete Node 80\n");
    head = delete_particular_element(80,head);
    print_linked_list(head);

    printf("Size of the linked list = %d\n", size_of_linked_list(head));
    printf("Middle Element of Linked List = %d\n", middle_element_of_linked_list(head));

    head = insert_at_last(10, head);
    print_linked_list(head);
    printf("Occurrences of 10 in the list = %d", count_occurrences(10,head));


}


