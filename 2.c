#include<stdio.h>
void callByVal(int a , int b)
{
	int temp = a;
	a=b;
	b=temp;
	printf("Value after Swapping : \nA=%d , B=%d",a,b);
}
void callByRef(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
	printf("Value after Swapping : \nA=%d , B=%d",*a,*b);
}
int main()
{
	int a , b;
	printf("Enter the values of A and B : ");
	scanf("%d %d", &a , &b);
	printf("Call by Reference swapping :\n");
	callByRef(&a,&b);
	printf("\nCall by Value swapping :\n");
	callByVal(a,b);
	return 0;
}
