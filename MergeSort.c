#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void mergesort(int *,int,int);
void merge(int *,int,int,int);

void main()
{
    int i,n,arr[100];
    printf("\nEnter the no of elements in array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of array one by one: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    mergesort(arr,0,n-1);

    printf("\n Sorted  elements are : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);


}

void mergesort(int arr[],int lb,int ub)
{

    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);

    }
}

void merge(int arr[],int lb1,int ub1,int ub2)
{

    int i,j,k,temp[50];
    i=lb1;
    j=ub1+1;
    k=0;

    while(i<=ub1 &&j<=ub2)
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];

    while(i<=ub1)
        temp[k++]=arr[i++];

    while(j<=ub2)
        temp[k++]=arr[j++];

    for(i=lb1,j=0;i<=ub2;i++,j++)
        arr[i]=temp[j];
}
