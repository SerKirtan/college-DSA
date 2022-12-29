//Merge sort
#include<stdio.h>

void merge(int arr[] , int first , int mid , int last)
{
    int sorted[last - first + 1];
    int idx1 = first;
    int idx2 = mid + 1 ;
    int x = 0;
    while (idx1 <= mid && idx2 <= last)
    {
        if(arr[idx1] <= arr[idx2])
            sorted[x++] = arr[idx1++];
        else
            sorted[x++] = arr[idx2++];
    }
    while(idx1 <= mid)
        sorted[x++] = arr[idx1++];
    while(idx2 <= last)
        sorted[x++] = arr[idx2++];
    for(int i = 0 , j = first ; i < sizeof(sorted)/sizeof(int) ; i++ , j++)
        arr[j] = sorted[i];
}

void divide(int arr[] , int first , int last)
{
    if(last <= first)
        return;
    int mid = first + (last - first)/2;
    divide(arr , first , mid);
    divide(arr , mid+1 , last);
    merge(arr , first , mid , last);
}

int main()
{
    int arr[] = {  28 , 74 , 8 , 35 , 60 , 11 , 23 , 43};
    int n = sizeof(arr)/ sizeof(int);
    divide(arr , 0 , n-1);
    printf("Sorted array :");
    for(int i = 0 ; i < n ; i++)
        printf(" %d", arr[i]);  
}
