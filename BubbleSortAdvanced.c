#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void bubble(int *,int);

void main()
{

    int i,n,arr[100];
    printf("\nEnter the no of elements in array: ");
    scanf("%d",&n);
    printf("\nEnter the no of elements one by one: ");
    for(i=0;i<n;i++)
        scanf("%d ",&arr[i]);
    bubble(arr,n);

    printf("\nthe sorted elements are: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void bubble(int arr[],int n)
{

    int flag=1,i,j,temp;
    for(i=0;i<n-1 && flag;i++)
    {

        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1
               ])
            {
            flag=1;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }

        }
    }
}

