//FOR CIRCULAR SINGLY LINKED LIST!!

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node* next;
    int data;
};

void display(struct node* tail)
{
    struct node* temp = tail->next;
    printf("\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != tail->next);
}

struct node* addToEmpty(struct node* tail , int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    tail = temp;
    return tail;
}

struct node* addAtEnd(struct node* tail , int data)
{
    struct node* temp = malloc(sizeof(struct node));
    struct node* ptr = tail->next;
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
    return tail;
}

struct node* addBeforePos(struct node* tail , int position , int data)
{
    struct node* temp = tail;
    struct node* add = malloc(sizeof(struct node));
    add->data = data;
    add->next = NULL;
    if(position < 1)
        printf("Invalid postion!");
    else
    {
        while(position != 1)
        {
            temp = temp->next;
            if(temp == tail)
            {
                printf("Invalid position!");
                return tail;
            }
            position--;
        }
        add->next = temp->next;
        temp->next = add;
        printf("Added!");
    }
    return tail;
}

struct node* deleteFirst(struct node* tail)
{
    struct node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    printf("Deleted!");
    return tail;
}

struct node* deleteAfterPos(struct node* tail , int position)
{
    struct node* temp = tail;
    if(position < 2 )
        printf("Invalid postion!");
    else
    {
        while(position != 1)
        {
            temp = temp->next;
            if(temp == tail)
            {
                printf("Invalid postion!");
                return tail;
            }
            position--;
        }
        struct node* ptr = temp->next;
        if(ptr == tail)
            tail = temp;
        temp->next = ptr->next;
        free(ptr);
        printf("Deleted!");
    }
    return tail;
}

struct node* createList(struct node* tail)
{
    int n , data;
    printf("Enter the number of elements you want : ");
    scanf("%d", &n);
    if(n < 1)
        return tail;
    printf("Enter element-1 : ");
    scanf("%d", &data);
    tail = addToEmpty (tail , data);
    for( int i = 1 ; i<n ; i++)
    {
        printf("Enter element-%d : " , i+1);
        scanf("%d", &data);
        tail = addAtEnd(tail , data);
    }
    return tail;
}

struct node* performOperations(struct node* tail)
{
    int ch = 0, data , position;
    while(ch != 6)
    {
        printf("\n\n1] Display\n2] Insert at end\n3] Insert before a position \n4] Delete first node \n5] Delete node after a position \n6] End Program\nEnter which operation you want to perform : ");
        scanf("%d" , &ch);
        switch(ch)
        {
        case 1: 
            display(tail);
            break;
        case 2: 
            printf("\nEnter which elememnt you want to enter at End : ");
            scanf("%d" , &data);
            tail = addAtEnd(tail , data);
            printf("Added!");
            break;
        case 3:
            printf("\nEnter which elememnt you want to enter and before which position : ");
            scanf("%d %d", &data , &position);
            tail = addBeforePos(tail , position , data);
            break;
        case 4:
            tail = deleteFirst(tail);
            break;
        case 5:
            printf("\nEnter after which position do you want to delete the node : ");
            scanf("%d" , &position);
            tail = deleteAfterPos(tail , position + 1 );
            break;
        case 6:
            break;
        default: printf("\nINVALID INPUT!");      
        }
    }
    return tail;
}

int main()
{
    struct node* tail = NULL;
    tail = createList(tail);
    tail = performOperations(tail);
}
