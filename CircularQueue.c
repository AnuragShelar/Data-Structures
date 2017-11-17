#include<stdio.h>
#include<stdlib.h>
#include<process.h>

#define MS 10

int cqueue[MS];
int front=-1;
int rear=-1;

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
        int ele,temp;

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
    if(front==(rear+1)%MS)
        printf("\nOverflow.");
    if(front==-1)
        front=rear=0;
    else
        rear=(rear+1)%MS;

        cqueue[rear]=ele;


}

int del()
{
    int e;
    e=cqueue[front];

    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MS;
    return e;

}

void display()
{
    int i=front;
    printf("The linear queue is: \n");
    if(i==-1)
        printf("Empty");
    for (i = front; i !=rear; i=(i+1)%MS)
        {
            printf (" %d\n",  cqueue[i]);
        }

}

