#include<stdio.h>
#define MS 5

int queue[MS][2];
int f=-1, r=-1;
int insert(int, int);
int delete();
void display();

int insert(int p, int e)
{
    if(r == MS-1)
    {
        printf("overflow");
        return ;
    }
   if(f==-1)
        f=r=0;
   else
        r++;
   queue[r][0]=p;
   queue[r][1]=e;
   printf("%d is inserted.\n", e);
}

int delete()
{
    int e, i, max;
    for(i=0; i<MS; i++)
    {
        if(max<queue[i][0])
            max=i;
    }
    e=queue[max][1];

    int temp1, temp2;

    for(i=max; i<MS-1; i++)
    {
        queue[i][0]=queue[i+1][0];
        queue[i][1]=queue[i+1][1];
    }
     r--;
     return e;

}
void display()
{
    int i;
    printf("The linear queue is: \n");
    printf("\nPriority\tElement\n");
    for (i = f; i <= r; i++)
        {
            printf ("%d\t\t %d\n", queue[i][0], queue[i][1]);
        }

}


main()
{
    int ch;
    int c, n, p;
    do
    {
        printf("---------------------------\n");
        printf("Enter 1 to insert\n");
        printf("Enter 2 to delete\n");
        printf("Enter 3 to display\n");
        printf("---------------------------\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("\tEnter the element to be inserted : ");
                scanf("%d", &n);
                printf("\tEnter the priority of the element : ");
                scanf("%d", &p);
                insert(p, n);
                break;
            case 2:
                if(f == -1)
                {
                    printf("Underflow!!\n");
                    break;
                }
                printf("The deleted element is : %d\n",delete());
                break;
            case 3:
                display();
                break;
        }
        printf("do you want to continue enter 1 to continue\n");
        scanf("%d",&c);
    }while(c==1);
}
