#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *last = NULL, *temp, *new_node;

void create();
void insert_begin();
void insert_end();
void insert_desired();
void delete_begin();
void delete_end();
void delete_desired();
void display();
void search();
void count_nodes();

void main()
{
    int choice;

    while (1)
    {
        printf("\n*******");
        printf("\n1. CREATE");
        printf("\n2. INSERT BEGIN");
        printf("\n3. INSERT END");
        printf("\n4. INSERT AT POSITION");
        printf("\n5. DELETE BEGIN");
        printf("\n6. DELETE END");
        printf("\n7. DELETE AT POSITION");
        printf("\n8. DISPLAY");
        printf("\n9. SEARCH");
        printf("\n10. COUNT NODES");
        printf("\n11. EXIT");
        printf("\n*******");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_desired();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_desired();
            break;
        case 8:
            display();
            break;
        case 9:
            search();
            break;
        case 10:
            count_nodes();
            break;
        case 11:
            exit(0);
        }
    }
}

void create()
{
    int n, i;
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &new_node->data);

        new_node->prev = new_node->next = NULL;

        if (head == NULL)
        {
            head = last = new_node;
        }
        else
        {
            last->next = new_node;
            new_node->prev = last;
            last = new_node;
        }
    }
}

void insert_begin()
{
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &new_node->data);

    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;

    if (last == NULL)
        last = new_node;
}

void insert_end()
{
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if (head == NULL)
    {
        new_node->prev = NULL;
        head = last = new_node;
    }
    else
    {
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
    }
}

void insert_desired()
{
    int pos, i;

    printf("Enter data: ");
    new_node = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new_node->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;

    if (new_node->next == NULL)
        last = new_node;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
    }
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nDeleted node is %d", head->data);
        temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            last = NULL;

        free(temp);
    }
}

void delete_end()
{
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nDeleted node is %d", last->data);
        temp = last;
        last = last->prev;

        if (last != NULL)
            last->next = NULL;
        else
            head = NULL;

        free(temp);
    }
}

void delete_desired()
{
    int pos, i;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position");
        return;
    }

    printf("\nDeleted node is %d", temp->data);

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        last = temp->prev;

    free(temp);
}

void search()
{
    int ele;
    printf("\nEnter element: ");
    scanf("%d", &ele);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            printf("Element found");
            return;
        }
        temp = temp->next;
    }

    printf("Element not found");
}

void count_nodes()
{
    int count = 0;
    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total nodes: %d", count);
}
