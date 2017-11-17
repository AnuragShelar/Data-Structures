#include<stdio.h>
#include<stdlib.h>
#include<process.h>

#define MS 10

void push(int);
int pop();

int top=-1;
int stack[MS];

int main()
{
    int n,i,array[10],temp;
    printf("\nenter the no of elements in array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of array one by one: ");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);

    for(i=0;i<n;i++)
        push(array[i]);

    for(i=0;i<n;i++)
    {

        temp=pop();
        array[i]=temp;

    }
    printf("The reversed elements are: ");
    for(i=0;i<n;i++)
        printf("%d ",array[i]);
}

void push(int temp)
{

    top++;
    stack[top]=temp;
}

int pop()
{

    return stack[top--];
}
