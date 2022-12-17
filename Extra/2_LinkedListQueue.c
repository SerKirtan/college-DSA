//Application of linked list in Queue

#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int data;
    struct Queue* next;
}*front , *rear;

void display()
{
    if(front == NULL)
        printf("\nQueue is empty!");
    else{
        struct Queue* temp = front;
        printf("\nQueue contains :");
        while(temp != NULL)
        {
            printf(" %d" , temp->data);
            temp = temp->next;
        }
    }
}

void push(int data)
{
    struct Queue* add = malloc(sizeof(struct Queue));
    struct Queue* ptr = rear;
    add->data = data;
    add->next = NULL;
    if( rear ==  NULL && front == NULL)
        rear = front = add;
    else{
        rear = add;
        ptr->next = rear;
    }
}

void pop()
{
    if(front == NULL)
        printf("\nQueue is empty!");
    else{
        struct Queue* temp = front;
        front = front->next;
        free(temp);
        printf("\nElement popped!");
    }
}

void createQueue()
{
    int size, data;
    front = rear = NULL;
    printf("Enter how many elements you want to enter in Queue : ");
    scanf("%d" , &size);
    if(size < 0)
        printf("Invalid Queue size!");
    else if( size == 0)
        printf("Empty Queue created!");
    else
    {
        for(int i = 0 ; i < size ; i++)
        {
            printf("Enter element-%d : ", i+1);
            scanf("%d" , &data);
            push(data);
        }
    }
}

void performOperations()
{
    int ch = 0, data;
    while(ch != 4)
    {
        printf("\n1] Display\n2] Push\n3] Pop\n4] End program\nEnter operation : ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1: display();
            break;
        case 2: printf("\nEnter which element you want to push : ");
            scanf("%d" , &data);
            push(data);
            printf("Added!");
            break;
        case 3: pop();
            break;
        case 4: break;
        default: printf("\nInvalid Input!");
        }
    }
}

int main()
{
    createQueue();
    performOperations();
}
