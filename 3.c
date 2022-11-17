#include <stdio.h>    
#define MAX 5
int stack[MAX] , top = -1;  

void change()
{
    int position , number;
    if(top == -1)
        printf("\nStack Empty!");
    else
    {
        printf("\nElement at which postion do you want to change : ");
        scanf("%d" , &position);
        if(position < 1 || position > top +1 )
            printf("Invalid postion!");
        else{
            printf("What do you want to change it to : ");
            scanf("%d" , &number);
            stack[top - position +1] = number;
            printf("Element changed!");
        }
    }
}

void peep()
{
    if( top == -1)
        printf("\nStack Empty!");
    else
        printf("\nElement at top is %d" , stack[top]);
}

void pop()
{
    if( top == -1)
        printf("\nStack Underflow!");
    else
        printf("\nElement popped!" , top--);
}

void push()
{
    int number;;
    if(top == MAX - 1)
        printf("\nStack Overflow!");
    else
    {
        printf("\nEnter which number do you want to push : ");
        scanf("%d" , &number);
        stack[++top] = number;
    }
}

void display()
{
    if(top == -1)
        printf("\nStack Empty!");
    else
    {
        printf("\nStack contains : ");
        for(int temp = top , i = 0 ; !(temp == -1) ; temp--)
            printf("%d]%d ", ++i , stack[temp]);
    }
}

void performOperation(int stack[])
{
    int ch = 0;
    while (ch != 6)
    {
        printf("\n\n1] Push\n2] Pop\n3] Peep\n4] Change\n5] Display\n6] End Program\nEnter which operation you want to do : ");
        scanf("%d" , &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            change();
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        default:
            printf("\nInvalid input!");   
        }
    }
}

int main() 
{
    performOperation(stack);
}
