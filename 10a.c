//BUBBLE SORT

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    printf("Enter number of elements you want in your array : ");
    scanf("%d" , &size);
    int arr[size];

    //INPUT
    printf("Enter array elements : ");
    for(int i = 0 ; i < size ; i++)
        scanf("%d" , &arr[i]);
    
    //SORTING
    for(int i = 0 ; i < size-1 ; i++)
        for(int j = 0 ; j < size-1-i ; j++)
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

    //DISPLAY
    printf("\nArray after sorting : ");
    for(int i = 0; i < size ; i++)
        printf("%d ", arr[i]);
}
