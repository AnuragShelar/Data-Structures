#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void pushA(int);
int popA();
int peekA();
void displayA();
void pushB(int);
int popB();
int peekB();
void displayB();

#define MAX 20

int topA=-1;
int topB=MAX;
int stack[MAX];

int main()
{
    int ch;

    do{
            printf("\n****MENU****\n");
            printf("\n1)Press 1 for PUSH in A");
            printf("\n2)Press 2 for POP in A");
            printf("\n3)Press 3 for PEEK in A");
            printf("\n4)Press 4 for PUSH in B");
            printf("\n5)Press 5 for POP in B");
            printf("\n6)Press 6 for PEEK in B");
            printf("\n7)Press 7 for DISPLAY in A");
            printf("\n8)Press 8 for DISPLAY in B");
            printf("\n9)Press 9 for EXIT");

            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            int eleA,valA,varA;
            int eleB,valB,varB;

            switch(ch)
            {

            case 1:

                printf("Enter the element to be pushed: ");
                scanf("%d",&eleA);
                pushA(eleA);
                break;

            case 2:

                valA=popA();
                printf("\nThe element to be popped is %d ",valA);
                break;

            case 3:

                varA=peekA();
                printf("The element at top is %d ",varA);
                break;


            case 4:

                printf("Enter the element to be pushed: ");
                scanf("%d",&eleB);
                pushB(eleB);
                break;

            case 5:

                valB=popB();
                printf("\nThe element to be popped is %d ",valB0);
                break;

            case 6:

                varB=peekB();
                printf("The element at top is %d ",varB);
                break;

            case 7:
                displayA();
                break;


            case 8:
                displayB();
                break;




            default:
                printf("Invalid choice");

            }



    }while(ch!=9);
}


void pushA(int eleA)
{

    if(topA==topB-1)
        printf("OVERFLOW..");
    else
    {
        topA++;
        stack[topA]=eleA;
    }

}

int popA()
{
    int varA;
        if(topA==-1)
    {
        printf("\nUNDERFLOW..");
        return;
    }

    else
    {
        varA=stack[topA];
        topA--;
        return varA;
    }
}

int peekA()
{

    if(topA==-1)
    {
        printf("\nUNDERFLOW..");
        return;
    }
    else
    {

        return stack[topA];
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
            printf("%d \n",stack[i]);

    }

}

void pushB(int eleB)
{

    if(topB==topA+1)
        printf("OVERFLOW..");
    else
    {
        topB--;
        stack[topB]=eleB;
    }

}

int popB()
{
    int varB;

    if(topB==MAX)
    {
        printf("\nUNDERFLOW..");
        return;
    }

    else
    {
        varB=stack[topB];
        topB++;
        return varB;
    }
}

int peekB()
{

    if(topB==MAX)
    {
        printf("\nUNDERFLOW..");
        return;
    }
    else
    {

        return stack[topB];
    }
}

void displayB()
{
    int i;
    if(topB==MAX)
        printf("\nStack is empty");
    else
    {
        for(i=topB;i<MAX;i++)
            printf("%d \n",stack[i]);

    }

}

