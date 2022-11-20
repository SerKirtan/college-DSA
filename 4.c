#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX] , infix[MAX] , postfix[MAX];
int resl[MAX];
int top = -1;

int pop2()
{
    if( top == -1)
        printf("\nStack Underflow!");
    else
        return resl[top--];
}

void push2(int num)
{
    if(top == MAX - 1)
        printf("\nStack Overflow!");
    else
        resl[++top] = num;
}

int evaluatePostfix()
{
    int i = 0 , n1 , n2 , temp = 1;
    char symbol;
    top = -1;
    while(postfix[i] != '\0')
    {
        symbol = postfix[i];
        switch(symbol)
        {
        case '+':
            push2(pop2() + pop2());
            break;
        case '-':
            n1 = pop2();
            n2 = pop2();
            push2(n2-n1);
            break;
        case '*':
            push2(pop2() * pop2());
            break;
        case '/':
            n1 = pop2();
            n2 = pop2();
            push2(n2/n1);
            break;
        case '^':
            n1 = pop2();
            n2 = pop2();
            while (n1 != 0){
                temp*=n2;
                n1--;
            }
            push2(temp);
            temp = 1;
            break;
        default: push2(symbol-48);
        }
        i++;
    }
    return resl[0];
}

int precedence(char s)
{
    switch(s)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3; 
    default:
        return 0;
    }
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int pop()
{
    if( top == -1)
        printf("\nStack Underflow!");
    else
        return stack[top--];
}

void push(char s)
{
    if(top == MAX - 1)
        printf("\nStack Overflow!");
    else
        stack[++top] = s;
}

void infixToPostfix()
{
    int j = 0 , i = 0;
    char symbol , next;
    while(infix[i] != '\0')
    for( ; i < strlen(infix) ; i++)
    {
        symbol = infix[i];
        switch(symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while((next = pop()) != '(')
                postfix[j++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;
        default:
            postfix[j++] = infix[i];
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main()
{
    printf("Enter the INFIX : ");
    gets(infix);
    infixToPostfix();
    printf("Postfix is %s" , postfix);
    printf("\nResult is %d" , evaluatePostfix());
}
