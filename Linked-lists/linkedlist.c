#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

/* Function to reverse the linked list */
void printReverse(struct Node* head)
{
    // Base case 
    if (head == NULL)
       return;
 
    // print the list after head node
    printReverse(head->next);
 
    // After everything else is printed, print head
    printf("%d ", head->data);
}

 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}
 
int main()
{   
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;
    
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
    
    // Link fourth and fifth nodes
    fourth->data = 21;
    fourth->next = fifth;

     // Link fifth and sixth nodes
    fifth->data = 35;
    fifth->next = sixth;
    
    // Link sixth and seventh nodes
    sixth->data = 12;
    sixth->next = seventh;
    

    // Terminate the list at the seventh node
    seventh->data = 32;
    seventh->next = NULL;
 
    linkedListTraversal(head); 
    printReverse(head);
    return 0;
}
