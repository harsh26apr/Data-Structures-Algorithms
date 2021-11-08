//Q3: C program to create and traverse Circular Linked List
#include<stdio.h>
#include<stdlib.h>

//Basic structure of Node
struct node {
    int data;
    struct node * next;
}*head;

//Functions used in this program
 
void createList(int n);
void displayList();
void reverseList();

int main()
{
    int n;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    if(n<7){
        printf("There should be atleast 7 nodes");
    }else{
    createList(n);
    displayList(head);
    reverseList(&head);
    
    printf("\n\n");
    }
    return 0;
}
//Creates a circular linked list of n nodes.
 
void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    if(n >= 1)
    {
        //Creates and links the head node
         
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

        //Loop for creating and linking rest of the n-1 nodes
         
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            // Link the previous node with newly created node
            prevNode->next = newNode;

            // Move the previous node ahead
            prevNode = newNode;
        }

        // Link the last node with first node
        prevNode->next = head;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

//Display the content of the list
 
void displayList()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}
void reverseList(struct node **head) 
{
    // Temporary helper variables
    struct node *prev, *cur, *next, *last;

    // Cannot reverse empty list
    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }


    // Head is going to be our last node after reversing list
    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    // Iterate till you reach the initial node in circular list
    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head = prev;       // Make last node as head
    printf("Reversed List is as below\n");
    displayList(head);
}
