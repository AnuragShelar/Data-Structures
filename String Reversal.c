#include<stdio.h>
#define MS 10

int stack[MS];
int top=-1;
void push(int);
int pop();

void main()
{

    int n,i,array[10],temp;
    printf("\nEnter the no of elements in the array:- ");
    scanf("%d",&n);
    printf("Enter the elements in stack one by one");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    for(i=0;i<n;i++)
        push(array[i]);
    for(i=0;i<n;i++)
    {
        temp=pop();
        array[i]=temp;
    }
    printf("\nThe reversed stack is:");
    for(i=0;i<n;i++)
        printf("\n%d",array[i]);
}

void push(int temp)
{

    stack[++top]=temp;
}

int pop()
{
    return (stack[top--]);

}
