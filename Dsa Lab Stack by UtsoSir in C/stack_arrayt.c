#include<stdio.h>

int s[100];
int topIdx = -1;

int isEmpty()
{
    if(topIdx == -1)
    {
        return 1;/// stack is empty
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(topIdx == 100-1)
    {
        return 1; /// stack is full
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if(!isFull())
    {
        topIdx++;
        s[topIdx] = data;
    }
    else
    {
        printf("Stack is full");
    }
}


int pop()
{
    if(!isEmpty())
    {
        int data = s[topIdx];
        topIdx--;
        return data;
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

int top()
{
    if(!isEmpty)
    {
        return s[topIdx];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

void display()
{
    printf("The element of the stack are: ");
    for(int i=topIdx; i>=0; i--)
    {
        printf("%d ", s[i]);
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


