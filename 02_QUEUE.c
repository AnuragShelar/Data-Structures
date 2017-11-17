#include<stdio.h>

void insert(int);
int delete();
void display();


int front=-1;
int rear=-1;

#define MS 4
int queue[MS];
int e;

int main()
{
    int choice;

    do
    {

        printf("\n*****MENU*****\n");
        printf("\nPress 1 for Insert");
        printf("\nPress 2 for Delete");
        printf("\nPress 3 for DISPLAY");
        printf("\nPress 4 for EXIT");

        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:

                printf("\nEnter the element to be inserted : ");
                scanf("%d",&e);

                insert(e);
                break;

            case 2:
                    if(front==-1)
                        printf("\nUnderflow...\n");
                    printf("The deleted element is %d",delete());

                break;

            case 3:
                display();
                break;

            case 4:
                break;

            default :
                printf("\nInvalid Entry !!");
        }
    }while(choice != 5);
}

void insert(int e)
{
      if(rear==MS-1)
        printf("\nOverflow....\n");

      if(front==-1)
        front=rear=0;
      else
        rear++;
      queue[rear]=e;


}
void display()
{
        int i;
        printf("\nThe QUEUE is....\n");

        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
}

int delete()
{

    int e;
    e=queue[front];
    if(front==rear)
            front=rear=-1;
    else
        front++;
    return e;

}

