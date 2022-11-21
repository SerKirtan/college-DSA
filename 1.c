#include<stdio.h>
void insert(int *a , int n)
{
	int pos, num , i;
	printf("Enter which index postion do you want to insert an number : ");
	scanf("%d", &pos);
	pos--;
	printf("Enter the number : ");
	scanf("%d", &num);
	for(i = (n-2) ; i != pos ; i--)
		a[i+1]=a[i];
	a[i+1]=num;
}

void deletion(int *a , int n)
{
	int pos;
	printf("Enter which postion do you want to delete the number : ");
	scanf("%d", &pos);
	for(int i = pos ; i < n ;  i++)
		a[i]=a[i+1];
}

void search(int *a , int n)
{
	int num;
	printf("Enter which number do you want to search : ");
	scanf("%d", &num);
	for(int i = 0 ; i < n ; i++)
	{
		if (a[i] == num)
			printf("Number found at index %d" , i);
	}
}

void display(int *a , int n)
{
	for (int i=0 ; i < n ; i++)
		printf("[%d] %d ", i , a[i]);
}

void input(int *a , int n)
{
	printf("Enter array elements : ");
	for(int i = 0 ; i < n ; i++)
		scanf("%d" ,&a[i]);
}

int main()
{
	int a[50] , n , check ;
	printf("Enter the sixe of array [1-20] : ");
	scanf("%d" , &n);
	input (a,n);
	
	do{
		printf("\n\n1]Insertion\n2]Deletion\n3]Search element\n4]Display array\n5]End program\nEnter which operation you want to do : ");
		scanf("%d" ,&check);
		switch(check)
		{
		case 1:
			n++;
			insert(a,n);
			break;	
		case 2:
			n--;
			deletion(a,n);
			break;
		case 3:
			search(a,n);
			break;
		case 4:
			display(a,n);
			break;
		case 5:
			break;	
		default:
			printf("INVALID INPUT!! -> Enter 1-5\n");
		}	
	}while(check != 5);
}
