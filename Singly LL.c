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

    printf("\nEnter the no of nodes: ");

    scanf("%d", &n);



    for (i = 0; i < n; i++)

    {

        new_node = (struct node *)malloc(sizeof(struct node));



        printf("Enter the data of the node: ");

        scanf("%d", &new_node->data);



        new_node->next = NULL;



        if (head == NULL)

        {

            head = last = new_node;

        }

        else

        {

            last->next = new_node;

            last = new_node;

        }

    }

}



void insert_begin()

{

    new_node = (struct node *)malloc(sizeof(struct node));



    printf("Enter the data of the node: ");

    scanf("%d", &new_node->data);



    new_node->next = head;

    head = new_node;

}



void insert_end()

{

    new_node = (struct node *)malloc(sizeof(struct node));



    printf("Enter the data of the node: ");

    scanf("%d", &new_node->data);



    new_node->next = NULL;



    if (head == NULL)

    {

        head = last = new_node;

    }

    else

    {

        last->next = new_node;

        last = new_node;

    }

}



void insert_desired()

{

    int pos, i;



    new_node = (struct node *)malloc(sizeof(struct node));



    printf("Enter the data of the node: ");

    scanf("%d", &new_node->data);



    printf("Enter the position: ");

    scanf("%d", &pos);



    new_node->next = NULL;



    temp = head;



    for (i = 1; i < pos - 1; i++)

    {

        temp = temp->next;

    }



    new_node->next = temp->next;

    temp->next = new_node;

}



void display()

{

    if (head == NULL)

    {

        printf("There are no nodes");

    }

    else

    {

        temp = head;

        while (temp != NULL)

        {

            printf("%d -> ", temp->data);

            temp = temp->next;

        }

    }

}

void delete_begin()

{

    if (head == NULL)

    {

        printf("\nThere are no nodes in the list:");

    }

    else

    {

        printf("\nDeleted node is %d", head->data);

        temp = head;

        head = head->next;

        free(temp);

    }

}

void delete_end()

{

    if (head == NULL)

    {

        printf("\nThere are no nodes in the list");

    }

    else if (head == last)

    {

        printf("\nDeleted node is %d", head->data);

        free(head);

        head = last = NULL;

    }

    else

    {

        temp = head;

        printf("\nDeleted node is %d", last->data);



        while (temp->next != last)

        {

            temp = temp->next;

        }



        free(last);

        temp->next = NULL;

        last = temp;

    }

}

void delete_desired()

{

    int pos, i;

    struct node *temp1;



    printf("\nEnter the pos of the node to delete");

    scanf("%d", &pos);



    if (head == NULL)

    {

        printf("\nThere are no nodes in the list");

    }

    else if (head == last)

    {

        printf("\nDeleted node is %d", head->data);

        free(head);

        head = last = NULL;

    }

    else

    {

        temp = head;



        for (i = 1; i < pos - 1; i++)

        {

            temp = temp->next;

        }



        printf("\nDeleted node is %d", temp->next->data);



        temp1 = temp->next;

        temp->next = temp->next->next;

        free(temp1);



        if (temp->next == NULL)

        {

            last = temp;

        }

    }

}

void search()

{

    int ele;

    printf("\nEnter the Search Element");

    scanf("%d", &ele);



    if (head == NULL)

    {

        printf("\nThere are no nodes in the list");

    }

    else

    {

        temp = head;



        while (temp != NULL)

        {

            if (ele == temp->data)

            {

                printf("Search element is found");

                return;

            }

            temp = temp->next;

        }



        printf("Search element is not found in the list");

    }

}

void count_nodes()

{

    int count = 0;



    temp = head;



    while (temp != NULL)

    {

        count = count + 1;

        temp = temp->next;

    }



    printf("No. of nodes in the list : %d", count);

}



