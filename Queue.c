#include<stdio.h>
#include<stdlib.h>
#include<process.h>

#define MS 10

int queue[MS];

void insert(int);
int del();
void display();

int front=-1;
int rear=-1;
int ele,temp;
int main()
{

    int ch;
    do{
        printf("\n****MENU****");
        printf("\n1) Insert");
        printf("\n2) Delete");
        printf("\n3) Display");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1:

                printf("\nEnter the element to be inserted : ");
                scanf("%d",&ele);
                insert(ele);
                break;

            case 2:

                if(front==-1)
                    printf("Underflow");

                temp=del();
                printf("\nThe deleted element is %d",temp);
                break;

            case 3:
                display();
                break;

            default:
                printf("\nInvalid choice");
                break;

        }
    }while(ch!=4);
}


void insert(int ele)
{
    if(rear==MS-1)
        printf("\nOverflow...");

    if(front==-1)
        front=rear=0;
    else
        rear++;
    queue[rear]=ele;

}

int del()
{
    int e;
    e=queue[front];

    if(front==rear)
        front=rear=-1;
    else
        front++;
    return e;

}

void display()
{

    int i;
    for(i=front;i<=rear;i++)
        printf(" %d ",queue[i]);
}
