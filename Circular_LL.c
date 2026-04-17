#include <stdio.h>

#include <stdlib.h>



struct node

{

    int data;

    struct node *next;

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

        printf("\n4. INSERT DESIRED POSITION");

        printf("\n5. DELETE BEGIN");

        printf("\n6. DELETE END");

        printf("\n7. DELETE DESIRED POSITION");

        printf("\n8. DISPLAY");

        printf("\n9. SEARCH");

        printf("\n10. COUNT NODES");

        printf("\n11. EXIT");

        printf("\n*******");



        printf("\nEnter Your Choice: ");

        scanf("%d", &choice);



        switch (choice)

        {

        case 1: create(); break;

        case 2: insert_begin(); break;

        case 3: insert_end(); break;

        case 4: insert_desired(); break;

        case 5: delete_begin(); break;

        case 6: delete_end(); break;

        case 7: delete_desired(); break;

        case 8: display(); break;

        case 9: search(); break;

        case 10: count_nodes(); break;

        case 11: exit(0);

        }

    }

}



// CREATE

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



        if (head == NULL)

        {

            head = last = new_node;

            new_node->next = head;

        }

        else

        {

            last->next = new_node;

            new_node->next = head;

            last = new_node;

        }

    }

}



// INSERT BEGIN

void insert_begin()

{

    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");

    scanf("%d", &new_node->data);



    if (head == NULL)

    {

        head = last = new_node;

        new_node->next = head;

    }

    else

    {

        new_node->next = head;

        head = new_node;

        last->next = head;

    }

}



// INSERT END

void insert_end()

{

    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");

    scanf("%d", &new_node->data);



    if (head == NULL)

    {

        head = last = new_node;

        new_node->next = head;

    }

    else

    {

        last->next = new_node;

        new_node->next = head;

        last = new_node;

    }

}



// INSERT DESIRED

void insert_desired()

{

    int pos, i;



    printf("Enter data: ");

    new_node = (struct node *)malloc(sizeof(struct node));

    scanf("%d", &new_node->data);



    printf("Enter position: ");

    scanf("%d", &pos);



    temp = head;



    for (i = 1; i < pos - 1 && temp->next != head; i++)

        temp = temp->next;



    new_node->next = temp->next;

    temp->next = new_node;



    if (temp == last)

        last = new_node;

}



// DISPLAY

void display()

{

    if (head == NULL)

    {

        printf("No nodes");

    }

    else

    {

        temp = head;

        do

        {

            printf("%d -> ", temp->data);

            temp = temp->next;

        } while (temp != head);

    }

}



// DELETE BEGIN

void delete_begin()

{

    if (head == NULL)

    {

        printf("No nodes");

    }

    else if (head == last)

    {

        printf("Deleted node is %d", head->data);

        free(head);

        head = last = NULL;

    }

    else

    {

        printf("Deleted node is %d", head->data);

        temp = head;

        head = head->next;

        last->next = head;

        free(temp);

    }

}



// DELETE END

void delete_end()

{

    if (head == NULL)

    {

        printf("No nodes");

    }

    else if (head == last)

    {

        printf("Deleted node is %d", head->data);

        free(head);

        head = last = NULL;

    }

    else

    {

        temp = head;



        while (temp->next != last)

            temp = temp->next;



        printf("Deleted node is %d", last->data);



        temp->next = head;

        free(last);

        last = temp;

    }

}



// DELETE DESIRED

void delete_desired()

{

    int pos, i;

    struct node *temp1;



    printf("Enter position: ");

    scanf("%d", &pos);



    if (head == NULL)

    {

        printf("No nodes");

        return;

    }



    temp = head;



    for (i = 1; i < pos - 1 && temp->next != head; i++)

        temp = temp->next;



    temp1 = temp->next;



    printf("Deleted node is %d", temp1->data);



    temp->next = temp1->next;



    if (temp1 == last)

        last = temp;



    free(temp1);

}



// SEARCH

void search()

{

    int ele;

    printf("Enter element: ");

    scanf("%d", &ele);



    if (head == NULL)

    {

        printf("No nodes");

        return;

    }



    temp = head;



    do

    {

        if (temp->data == ele)

        {

            printf("Element found");

            return;

        }

        temp = temp->next;

    } while (temp != head);



    printf("Element not found");

}



// COUNT NODES

void count_nodes()

{

    int count = 0;



    if (head == NULL)

    {

        printf("No nodes");

        return;

    }



    temp = head;



    do

    {

        count++;

        temp = temp->next;

    } while (temp != head);



    printf("No. of nodes: %d", count);

} 


