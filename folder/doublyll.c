//Q2:Doubly linked list
#include <stdio.h>
#include <stdlib.h>

//Basic structure of Node
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

//Functions used in this program 
void createList(int n);
void displayList();
void displayreverselist();


int main()
{
    int n, choice;

    head = NULL;
    last = NULL;
    
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    if(n<7){
        printf("There should be atleast 7 nodes!");
    }else
    {
    createList(n); // Create list of n nodes
    displayList();
    displayreverselist();
    return 0;
    }
}

//Create a doubly linked list of n nodes.

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            /*
             * Create rest of the n-1 nodes
             */
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; // Link new node with the previous node
                    newNode->next = NULL;

                    last->next = newNode; // Link previous node with the new node
                    last = newNode;       // Make new node as last/previous node
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}


//Displays the doubly linked list (beginning to end)
 
void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;
            
            // Move the current pointer to next node 
            temp = temp->next;
        }
    }
}


//Reverses the DLL
void displayreverselist()
{
    struct node * temp;
    int n = 0;

    if(last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        printf("\n\nDATA IN REVERSED LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of last-%d node = %d\n", n, temp->data);

            n++;
            
            // Move the current pointer to previous node 
            temp = temp->prev; 
        }
    }
}