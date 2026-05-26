#include<stdio.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* tos; /// head of linked list

struct Node* create_new_node(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int isEmpty()
{
    if(tos == NULL)
    {
        return 1; /// stack is empty
    }
    else
    {
        return 0; /// stack is not empty
    }
}


void push(int data)
{
    struct Node* new_node = create_new_node(data);

    if(tos == NULL)
    {
        tos = new_node;
    }
    else
    {
        /// insert at first
        new_node->next = tos;
        tos = new_node;
    }
}

int top()
{
    /// only return the value of top element. No deletion
    if( tos == NULL)
    {
         printf("Stack is empty\n");
         return -1;
    }
    else
    {
        return tos->data;
    }
}

int pop()
{
    if(isEmpty() == 1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int topElement = top();
        struct Node* temp = tos;
        tos = tos->next;
        free(temp);
        return topElement;
    }
}

void display()
{
    struct Node* temp = tos;
    printf("The element of the stack are: ");
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
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
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
            push(data);
            break;
        case 2:
            /// Pop an element;
            data = pop();
            printf("Popped element is %d\n", data);
            break;
        case 3:
            /// Top Element
            data = top();
            printf("Top element of the stack is %d\n", data);
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
