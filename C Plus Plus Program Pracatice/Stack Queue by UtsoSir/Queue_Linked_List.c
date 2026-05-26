#include<stdio.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* front; /// head of linked list

struct Node* create_new_node(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int isEmpty()
{
    if(front == NULL)
    {
        return 1; /// queue is empty
    }
    else
    {
        return 0; /// queue is not empty
    }
}


void enqueue(int data)
{
    struct Node* new_node = create_new_node(data);

    if(front == NULL)
    {
        front = new_node;
    }
    else
    {
        /// insert at last
        struct Node* temp = front;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int front_element()
{
    /// only return the value of top element. No deletion
    if( front == NULL)
    {
         printf("Queue is empty\n");
         return -1;
    }
    else
    {
        return front->data;
    }
}

int dequeue()
{
    if(isEmpty() == 1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int frontElement = front_element();
        struct Node* temp = front;
        front = front->next;
        free(temp);
        return frontElement;
    }
}

void display()
{
    struct Node* temp = front;
    printf("The element of the element are: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int option, data;

    while(1)
    {
        printf("\n!!!MENU!!!\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            /// push an element
            printf("Enter New Element: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            /// Pop an element;
            data = dequeue();
            printf("Dequeued element is %d\n", data);
            break;
        case 3:
            /// Top Element
            data = front_element();
            printf("Front element of the queue is %d\n", data);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Not valid Option. Choose again\n");
        }
    }
}

