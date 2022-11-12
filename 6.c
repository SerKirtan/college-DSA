#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void display(struct node* head)
{
    struct node* temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }    
}

struct node* addToEmpty(struct node* head , int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->link = NULL;
    temp->data = data;
    head = temp;
    return head;
}

struct node* addAtEnd(struct node* head, int data)
{
    if(head == NULL)
        head = addToEmpty(head , data);
    struct node *ptr,*temp;
    ptr = head;
    temp = malloc(sizeof(struct node));
    temp->link = NULL;
    temp->data = data ;
    while(ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
    return head;
}

struct node* addAtBegining(struct node* head , int data)
{
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}

struct node* createList(struct node* head)
{
    int n, data;
    printf("Enter number of elements you want : ");
    scanf("%d",&n);
    if(n<0)
        return head;
    printf("Enter the element-1 : ");
    scanf("%d", &data);
    head = addToEmpty(head , data);
    for(int i = 1 ; i < n ; i++)
    {
        printf("Enter the element-%d : " , i+1);
        scanf("%d", &data);
        head = addAtEnd(head,data);
    }
    return head;
}

struct node* deleteFirst(struct node* head)
{
    struct node* temp = head;
    head = head->link;
    free(temp);
    printf("Deleted!");
    return head;
}

struct node* deleteSpecific(struct node* head , int position)
{
    struct node* temp = head ;
    struct node* delPtr = head ;
    if (position < 1)
        printf("Invalid node position!");
    else if (position == 1)
        head = deleteFirst(head);
    else
    {
        while(position != 2)
        {
            position--;
            temp = temp->link;
            delPtr = delPtr->link;
            if(temp->link == NULL)
            {
                printf("Invalid node position!");
                return head;
            }
        }
        delPtr = delPtr->link;
        temp->link = delPtr->link;
        free (delPtr);
        printf("Deleted!");
    }
    return head;
}

struct node* performOperations(struct node* head)
{
    int ch = 0 , data;

    while (ch!=8)
    {
        printf("\n\nEnter which of the following operations you want to do :\n1] Display node\n2] Insert node at begining\n3] Insert node at End\n4] Insert a node such that linked list is in ascending order\n5] Delete first node\n6] Delete node before a specific position\n7] Delete node after a specific postion\n8] End program\nEnter number : ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("\nEnter number to add at beginning : ");
            scanf("%d" , &data);
            head = addAtBegining (head , data);
            printf("Added!");
            break;
        case 3:
            printf("\nEnter number to add at end : ");
            scanf("%d" , &data);
            head = addAtEnd (head , data);
            printf("Added!");
            break;
        case 4: //DOUBT [create sort function first? or provided linked list is already sorted?]
            break;
        case 5:
            head = deleteFirst(head);
            break;
        case 6:
            printf("\nEnter before which position do you want to delete the element : ");
            scanf("%d" , &data);
            head = deleteSpecific(head , data - 1);
            break;
        case 7:
            printf("\nEnter after which position do you want to delete the element : ");
            scanf("%d" , &data);
            head = deleteSpecific(head , data + 1);
            break;
        case 8:
            break;
        default: printf("\nInvalid input (please input a valid number)\n");
        }
    }  
    return head;
}

int main()
{
    struct node* head = NULL;
    head = createList(head);
    head = performOperations(head);  
}
