#include<iostream>
using namespace std;
void insert(int *a , int n)
{
	int pos, num , i;
	cout << "Enter which index postion do you want to insert an number : ";
	cin >> pos;
	pos--;
	cout << "Enter the number : ";
	cin >> num;
	for(i = (n-2) ; i != pos ; i--)
		a[i+1]=a[i];
	a[i+1]=num;
}

void deletion(int *a , int n)
{
	int pos;
	cout << "Enter which postion do you want to delete the number : ";
	cin >> pos;
	for(int i = pos ; i < n ;  i++)
		a[i]=a[i+1];
}

void search(int *a , int n)
{
	int num;
	cout << "Enter which number do you want to search : ";
	cin >> num;
	for(int i = 0 ; i < n ; i++)
	{
		if (a[i] == num)
			cout << "Number found at index "<< i << endl;
	}
}

void display(int *a , int n)
{
	for (int i=0 ; i < n ; i++)
		cout << i << "]" << " "<< a[i]<<endl;
}

void input(int *a , int n)
{
	cout << "Enter array elements : ";
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
}

int main()
{
	int a[50] , n , check ;
	cout << "Enter the sixe of array [1-20] : ";
	cin >> n;
	input (a,n);
	
	do{
		cout << "1]Insertion\n2]Deletion\n3]Search element\n4]Display array\n5]End program\nEnter which operation you want to do : ";
		cin >> check ;
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
			cout << "INVALID INPUT!! -> Enter 1-5\n";
		}	
	}while(check != 5);
}
