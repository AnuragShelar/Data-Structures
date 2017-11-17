#include<stdio.h>

void push(int);
int pop();
int peak();
void display();

int top=-1;

#define MS 4
int stack[MS];
int e;

int main()
{
    int choice;

    do
    {

        printf("*****MENU*****");
        printf("\nPress 1 for PUSH");
        printf("\nPress 2 for POP");
        printf("\nPress 3 for PEAK");
        printf("\nPress 4 for DISPLAY");
        printf("\nPress 5 for EXIT");

        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:



                printf("\nEnter the element to be inserted: ");
                scanf("%d",&e);

                push(e);
                break;


            case 2:
                if(top==-1)
                {
                    printf("\nUnderflow\n");
                    break;
                }
                pop();
                break;

            case 3:
                printf("\n The element at top is %d\n",peak());
                break;

            case 4:
                display();
                break;

            case 5:
                break;

            default :
                printf("\nInvalid Entry !!");

        }
    }while(choice != 5);
    return 0;
}

void push(int e)
{

    if(top==MS-1)
    {
        printf("\nOverflow\n");
        return;
    }
    top=top+1;
    stack[top]=e;
}
void display()
{
    int i;
    printf("\nThe stack is ...\n");
    for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
}
int peak()
{
    if(top==-1)
    {
        printf("\nStack is empty\n");
        return;
    }
    return stack[top];
}
int pop()
{
    int e;
    e=stack[top];
    top--;
    return e;
}



