//CIRCULAR QUEUE

#include<stdio.h>
#define MAX 5
int rear = -1 , front = -1;
int queue[MAX];

void enqueue()
{
    if( rear == MAX - 1 && front == 0 || rear == (front-1)) // Full Queue
        printf("\nQueue is full!");
    else
    {
        int data;
        printf("\nEnter element to queue : ");
        scanf("%d" , &data);
        if( rear == -1 && front == -1){ //Empty queue
            rear = front = 0;
            queue[rear] = data;
        }
        else if(rear == MAX -1 && front != 0){
            rear = 0;
            queue[rear] = data;
        }
        else
            queue[++rear] = data;
        printf("Added!");
    }
}

void dequeue()
{
    if( front == -1 && rear == -1 )
        printf("\nQueue is empty!");
    else if(front == rear){
        front = -1;
        rear = -1;
        printf("Deleted!");
    }
    else if(front == MAX - 1){
        front = 0;
        printf("Deleted!");
    }
    else{
        front++;
        printf("Deleted");
    }
}

void display()
{
    int i;
    if( front == -1 && rear == -1)
        printf("\nQueue is empty!");
    else
    {
        printf("\nQueue :");
        for(i = front ; i != rear ; i++)
        {
            printf(" %d", queue[i]);
            if(i == (MAX -1))
                i = -1;
        }
        printf(" %d", queue[rear]);
    }
}

void performOperations()
{
    int ch = 0;
    while(ch != 4)
    {
        printf("\n\n1] Insert\n2] Delete\n3] Display\n4] End program\nEnter which operation do you want to do : ");
        scanf("%d" , &ch);
        switch(ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:  
            printf("\nInvalid Input!!");  
        }
    }
}

int main()
{
    performOperations();
}
