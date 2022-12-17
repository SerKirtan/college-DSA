//Linked list implementaion in stack

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* below;
};

void display(struct stack* top)
{
    if(top == NULL)
        printf("\nStack is empty!");
    else{
        struct stack* temp = top;
        printf("\nStack contains :");
        while(temp != NULL)
        {
            printf(" %d" , temp->data);
            temp = temp->below;
        }
    }
}

struct stack* addToStack(struct stack* top , int data)
{
    struct stack* add = malloc(sizeof(struct stack));
    add->data = data;
    add->below = top;
    top = add;
    return top;
}

struct stack* push(struct stack* top)
{
    int data;
    printf("\nEnter which element you want to push : ");
    scanf("%d" , &data);
    top = addToStack(top , data);
    printf("\nElement pushed!");
    return top;
}

struct stack* pop(struct stack* top)
{
    if( top == NULL)
        printf("\nStack is empty!");
    else{
        struct stack* temp = top;
        top = top->below;
        free(temp);
        printf("\nElement Poped!");
    }
    return top;
}

struct stack* createStack(struct stack* top)
{
    int size , data;
    printf("Enter how many elements you want to enter in stack : ");
    scanf("%d" , &size);
    for( int i = 0 ; i < size ; i++)
    {
        printf("Enter element-%d : " , i+1);
        scanf("%d" , &data);
        top = addToStack(top , data);
    }
    return top;
}

void performOperations(struct stack* top)
{
    int ch = 0;
    while(ch != 4)
    {
        printf("\n\n1]Display\n2]Push\n3]Pop\n4]End program\nEnter operation : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: display(top);
            break;
        case 2: top = push(top);
            break;
        case 3: top = pop(top);
            break;
        case 4:
            break;
        default: printf("Invalid input!");
        }
    }
}

int main()
{
    struct stack* top = NULL;
    top = createStack(top);
    performOperations(top);
}
