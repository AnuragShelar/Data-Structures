#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void selectionsort(int *,int);

void main()
{
    int i,n,arr[100];
    printf("\nEnter the no of elements in array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of array one by one: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    selectionsort(arr,n);

    printf("\n Sorted  elements are : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);


}
void selectionsort(int arr[],int n)
{

    int small,index,i,j;
    for(i=0;i<n-1;i++)
    {
        small=arr[i];
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<small)
            {
                small=arr[j];
                index=j;

            }

        }
        arr[index]=arr[i];
        arr[i]=small;

    }
}

