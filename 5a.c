//SIMPLE QUEUE

#include<stdio.h>
#define MAX 5
int rear = -1 , front = -1;
int queue[MAX];

void enqueue()
{
    if( rear == MAX -1) // Full Queue
        printf("\nQueue is full!");
    else
    {
        int data;
        printf("\nEnter element to queue : ");
        scanf("%d" , &data);
        if( rear == -1 && front == -1) //Empty queue
        {
            rear = front = 0;
            queue[front] = data;
        }
        else
            queue[++rear] = data;
        printf("\nAdded!");
    }
}

void dequeue()
{
    if( front == -1 && rear == -1 || front > rear)
        printf("\nQueue is empty!");
    else if(front == MAX-1 && rear == MAX-1){
        front = rear = -1;
        printf("\nDeleted");
    }
    else{
        front++;
        printf("\nDeleted");
    }
}

void display()
{
    if( front == -1 && rear == -1 || front > rear)
        printf("\nQueue is empty!");
    else
    {
        printf("\nQueue :");
        for(int i = front ; i <= rear ; i++)
            printf(" %d", queue[i]);
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
