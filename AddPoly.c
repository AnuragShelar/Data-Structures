#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define NULL 0

struct Node
{
    int coeff,pow;
    struct Node *next;

};
  struct Node *poly1=NULL,*poly2=NULL,*poly=NULL;

void create(int a,int b,struct Node *pq)
{
    pq=(struct Node*)malloc(sizeof(struct Node));
    pq->coeff=a;
    pq->pow=b;
    pq->next=NULL;


}
void add(struct Node *p1,struct Node *p2,struct Node *p3)
{
    while(p1->next!=0 && p2->next!=0)
    {


    if(p1->pow>p2->pow)
    {
        p3->coeff=p1->coeff;
        p3->pow=p1->pow;
        p1=p1->next;
    }
    else if(p1->pow<p2->pow)
    {

        p3->coeff=p2->coeff;
        p3->pow=p2->pow;
        p2=p2->next;
    }
    else
    {

        p3->pow=p1->pow;
        p3->coeff=p1->coeff+p2->coeff;
        p1=p1->next;
        p2=p2->next;
    }
    }

}

void show(struct Node *p)
{

    while(p->next!=NULL)
    {

        printf("%dx^%d",p->coeff,p->pow);
        p=p->next;
        if(p->next!=NULL)
            printf(" + " );
    }
}

void main()
{

    struct Node q;

    create(2,2,&poly1);
    create(5,1,&poly1);
    create(2,0,&poly1);

    create(3,1,&poly2);
    create(6,0,&poly2);

    printf("1st number");
    show(poly1);

    printf("\n2nd number");
    show(poly2);
    poly=(struct Node*)malloc(sizeof(struct Node));
    add(&poly1,&poly2,&poly);

    printf("\nadded polynomial is");
    show(poly);
}
