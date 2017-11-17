#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MS 10
int stack[MS];
int topA=-1,topB=MS;

void pushA(int val)
{

    if(topA==topB-1)
        printf("\nOVERFLOW...\n");
    else
    {
        topA++;
        stack[topA]=val;
    }
}


int popA()
{
    int temp;
    if(topA==-1)
        printf("\nunderflow...");
    else
    {
        temp=stack[topA];
        topA--;
        return temp;
    }

}

void displayA()
{

    int i;
    if(topA==-1)
        printf("\nStack is empty");
    else
    {
        for(i=topA;i>=0;i--)
            printf("\t %d",stack[i]);
    }
}

void pushB(int val)
{

    if(topB==topA+1)
        printf("\noverflow...\n");
    else
    {
        topB--;
        stack[topB]=val;
    }
}

int popB()
{

    int temp;
    if(topB==MS)
        printf("\nUNDERFLOW\n");
    else
    {
        temp=stack[topB];
        topB++;
    }
}

void displayB()
{
    int i;
    if(topB==MS)
        printf("\nStack is empty");
    else
    {
        for(i=topB;i<MS;i++)
            printf("\t%d",stack[i]);
    }
}

void main()
{
    int choice;
    int val;
    do
    {
        printf("\n*****MENU*****\n");
        printf("\nPress 1) for PUSH IN STACK A");
        printf("\nPress 2) for PUSH IN STACK B");
        printf("\nPress 3) for POP IN STACK A");
        printf("\nPress 4) for POP IN STACK B");
        printf("\nPress 5) for DISPLAY IN STACK A");
        printf("\nPress 6) for DIPSLAY IN STACK B");
        printf("\nPress 7) for EXIT");

        printf("\n Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            printf("\nEnter the element to be inserted in stack A : ");
            scanf("%d",&val);

            pushA(val);
            break;

        case 2:
            printf("\nEnter the element to be inserted in stack B : ");
            scanf("%d",&val);

            pushB(val);
            break;

        case 3:
            val=popA();
            printf("\nthe value popped from stack A is %d",val);
            break;

        case 4:
            val=popB();
            printf("\nthe value popped from stack B is %d",val);
            break;

        case 5:
            displayA();
            break;

        case 6:
            displayB();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("\nInvalid input..\n");
        }
    }while(choice!=7);

}
