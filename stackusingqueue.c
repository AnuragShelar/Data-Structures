#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define QS 10

struct Queue1
{
    int items[QS];
    int front,rear;
};
struct Queue2
{
    int items[QS];
    int front,rear;
};

void insertA(struct Queue1 *pq,int x)
{

    if(pq->rear==QS-1)
        printf("Queue is full");
    else
        pq->items[++pq->rear]=x;
}

void insertB(struct Queue2 *pq,int x)
{
    if(pq->rear==QS-1)
        printf("\nQueue is full...");
    else
        pq->items[++pq->rear]=x;
}

int del(struct Queue1 *pq1,struct Queue2 *pq2)
{
    int temp1,temp2;
    if(pq1->front>pq1->rear)
        printf("underflow");
    else
         while(q1.size()!=1)
    {
        temp1=pq1->items[pq1->front++];

        temp2=insertB(&q2 ,temp1);
    }
    return temp1;
}

void display(struct Queue2 q2)
{
    int i;
    for(i=q2.front;i<q2.rear;i++)
        printf("%d",q2.items[i]);
}

  int main()
{
    int ch,x,temp;
    struct Queue1 q1;
    struct Queue2 q2;
    q1.front=0;
    q1.rear=-1;
    q2.front=0;
    q2.rear=-1;

    do
    {

        printf("\n*****MENU*****\n");
        printf("\nPress 1 for Insert");
        printf("\nPress 2 for Delete");
        printf("\nPress 3 for DISPLAY");
        printf("\nPress 4 for EXIT");


        printf("\nEnter your choice:-");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:

                printf("\nEnter the element to be inserted : ");
                scanf("%d",&x);


                insert(&q1,x);
                break;

            case 2:


                temp=del(&q1,&q2);
                printf("\nthe deleted element is %d",temp);
                break;

            case 3:
                display(q2);
                break;

            case 4:
                exit(0);
                break;

            default :
                printf("\nInvalid Entry !!");
        }
    }while(ch != 4);
}
