#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void insertionsort(int *,int);

void main()
{
    int i,n,arr[100];
    printf("\nEnter the no of elements in array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of array one by one: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    insertionsort(arr,n);

    printf("\n Sorted  elements are : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);


}

void insertionsort(int arr[],int n)
{

    int i,j,y;
    for(i=1;i<n;i++)
    {
        y=arr[i];
        for(j=i-1;j>=0 && y<arr[j];j--)
        {
        arr[j+1]=arr[j];
            arr[j]=y;

        }
    }
}
