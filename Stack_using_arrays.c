#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1, size;

void push();
void pop();
void display();

void main()
{
    int choice;

    printf("Enter stack size: ");
    scanf("%d", &size);

    stack = (int *)malloc(size * sizeof(int));

    while (1)
    {
        printf("\n*******");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\n*******");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}

void push()
{
    int x;

    if (top == size - 1)
    {
        printf("Stack is full");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Deleted element is %d", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d -> ", stack[i]);
        }
    }
}
