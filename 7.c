#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

void display(struct node* head)
{
    struct node* temp = head;
    printf("\n");
    if(head == NULL)
        printf("List Empty!");
    else
    {
        while( temp != NULL )
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

struct node* addToEmpty(struct node* head , int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head; 
}

struct node* addAtEnd(struct node* head, int data)
{
    if(head == NULL)
        head = addToEmpty(head , data);
    struct node* temp , *ptr;
    ptr = head ;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    while(ptr->next != NULL)
        ptr = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    return head;
}

struct node* addAtFront(struct node* head , int data)
{
    struct node* temp = malloc(sizeof(struct node));
    if(head == NULL)
        head = addToEmpty(head , data);
    temp->next = head;
    temp->prev = NULL;
    temp->data = data;
    head->prev = temp;
    head = head->prev;
    return head;
}

struct node* deleteLast(struct node* head)
{
    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    printf("Deleted!");
    return head;
}

struct node* deleteBefore(struct node* head , int position)
{
    struct node* temp = head;
    if(position < 1)
        printf("Invalid position!");
    while(position != 1)
    {
        position--;
        temp = temp->next;
    }
    if(temp->next == NULL)
        deleteLast(head);
    else
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        printf("Deleted!");
    }
    return head;
}


struct node* createList(struct node* head)
{
    int data , n;
    printf("Enter the number of elements you want : ");
    scanf("%d" , &n);
    if(n<1)
        return head;
    printf("Enter element-1 : ");
    scanf("%d", &data);
    head = addToEmpty(head , data);
    for(int i = 1 ; i < n ; i++)
    {
        printf("Enter element-%d : " , i+1);
        scanf("%d", &data);
        head = addAtEnd(head , data);
    }
    return head;
}

struct node* performOperations(struct node* head)
{
    int ch = 0 , data;
    while(ch != 6)
    {
        printf("\n\nEnter which operation do you want to do :\n1] Display list\n2] Insert node at front\n3] Insert node at end\n4] Delete last node\n5] Delete node before specific position\n6] End program\nEnter : ");
        scanf("%d" , &ch);
        switch(ch)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("\nEnter which number do you want to add at the front : ");
            scanf("%d" , &data);
            head = addAtFront(head , data);
            printf("Added!");
            break;
        case 3:
            printf("\nEnter which number do you want to add at the end : ");
            scanf("%d" , &data);
            head = addAtEnd(head , data);
            printf("Added!");
            break;
        case 4:
            head = deleteLast(head);
            break;
        case 5:
            printf("\nEnter before which postion do you want to delete : ");
            scanf("%d" , &data);
            head = deleteBefore(head , data-1);
            break;
        case 6:
            break;
        default:
            printf("\nNumber entered is invalid!");
        }
    }
}

int main()
{
    struct node* head = NULL;
    head = createList(head);
    head = performOperations(head);
}
