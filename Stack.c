#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void push(int);
int pop();
int peek();
void display();

#define MAX 10

int top=-1;
int stack[MAX];

int main()
{
    int ch;

    do{
            printf("\n****MENU****\n");
            printf("\n1)Press 1 for PUSH");
            printf("\n1)Press 2 for POP");
            printf("\n1)Press 3 for PEEK");
            printf("\n1)Press 4 for DISPLAY");
            printf("\n1)Press 5 for EXIT");

            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            int ele,val,var;

            switch(ch)
            {

            case 1:

                printf("Enter the element to be pushed: ");
                scanf("%d",&ele);
                push(ele);
                break;

            case 2:

                val=pop();
                printf("\nThe element to be popped is %d ",val);
                break;

            case 3:

                var=peek();
                printf("The element at top is %d ",var);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(1);
                break;

            default:
                printf("Invalid choice");

            }



    }while(ch!=6);
}


void push(int ele)
{

    if(top==MAX-1)
        printf("OVERFLOW..");
    else
    {
        top++;
        stack[top]=ele;
    }

}

int pop()
{
    int var;

    if(top==-1)
    {
        printf("\nUNDERFLOW..");
        return;
    }

    else
    {
        var=stack[top];
        top--;
        return var;
    }
}

int peek()
{

    if(top==-1)
    {
        printf("\nUNDERFLOW..");
        return;
    }
    else
    {

        return stack[top];
    }
}

void display()
{
    int i;
    if(top==-1)
        printf("\nStack is empty");
    else
    {
        for(i=top;i>=0;i--)
            printf("%d \n",stack[i]);

    }

}
