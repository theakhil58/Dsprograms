#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL, *temp, *new_node;

void push();
void pop();
void display();

void main()
{
    int choice;

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
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &new_node->data);

    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp = top;
        printf("Deleted element is %d", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
}
