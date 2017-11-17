#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void shellsort(int *,int);

void main()
{
    int i,n,arr[100];
    printf("\nEnter the no of elements in array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of array one by one: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    shellsort(arr,n);

    printf("\n Sorted  elements are : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

}

void shellsort(int arr[],int n)
{

    int incr,i,j,y;
    incr=n/2;
    while(incr>=1)
        {
            for(i=incr;i<n-1;i++)
            {
                y=arr[i];
                for(j=i-incr;j>=0 && y<arr[j];j=j-incr)
                {
                    arr[j+incr]=arr[j];
                    arr[j]=y;
                }


            }
            incr=incr/2;
    }
}

