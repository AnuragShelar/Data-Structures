#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define NULL 0


struct Node
{
    int data;
    struct Node *next;

};

struct Node *first=NULL,*last=NULL;

void create()
{
    struct Node *pnode,*current;
    pnode=(struct Node*)(malloc(sizeof(struct Node)));
    int ch;
    do
    {
        if(pnode==NULL)
        {
            printf("\nMEMORY FULL.....CANNOT ADD");
            exit(1);
        }
        else
        {
            printf("Emter the data value of node  :  ");
            scanf("%d",&pnode->data);

            if(first==NULL)
                first=last=pnode;
            else
            {

                last->next=pnode;
                last=pnode;
            }
            last->next=first;
        }
        printf("Do you wanna add another node:  Press 'Y'  or 'N'  : ");
        scanf("%s",&ch);

    }while(ch=='Y' || ch=='y');

}

void insertafter()
{
    struct Node *pnode,*current;
    pnode=(struct Node*)(malloc(sizeof(struct Node)));
    int x;

    if(pnode==NULL)
        printf("\nMEMORY FULL");
    else
    {
        printf("\nEnter the data to be inserted: ");
        scanf("%d",&pnode->data);
        printf("\Enter the data value after which data has to be inserted: ");
        scanf("%d",&x);
        current=first;

        while(current->data!=x && current!=last)
            current=current->next;
            if(current->data!=x)
                printf("Specified node not found");
            else
            {



        if(current==last)
        {
            last->next=pnode;
            last=pnode;
            last->next=first;
        }
        else
        {

            pnode->next=current->next;
            current->next=pnode;
        }
    }

    }
}

void insertbefore()
{

    struct Node *pnode,*current,*follow;
    pnode=(struct Node*)(malloc(sizeof(struct Node)));
    int x;

    if(pnode==NULL)
        printf("\nMEMORY FULL");
    else
    {
        printf("\nEnter the data to be inserted");
        scanf("%d",&pnode->data);
        printf("\Enter the data value after which data has to be inserted");
        scanf("%d",&x);
        current=first;
        follow=NULL;

        while(current->data!=x && current!=last)
            {
                follow=current;
                current=current->next;
            }
            if(current->data!=x)
                printf("Specified node not found");
            else
            {

                if(current==first)
                {
                    pnode->next=first;
                    first=pnode;
                    last->next=pnode;
                }
                else
                {


                    pnode->next=current;
                    follow->next=pnode;
                }
            }
    }
}

void delete1()
{
    int x;
    struct Node *current,*follow;
    printf("enter the data item to be deleted: ");
    scanf("%d",&x);
    current=first;
    while(current->data!=x&& current!=NULL)
    {

        follow=current;
        current=current->next;

    }
    if(current->data!=x)
        printf("specified node not found");
    else if(current==first)
    {
        first=first->next;
        last->next=first;

    }
else if(current==last)
{
    last=follow;
    last->next=first;
}
else
    follow->next=current->next;

    free(current);



}

void traverse()
{

    struct Node *current;
    if(first==NULL)
        printf("\nEmpty");
    else
    {

        current=first;

        while(current->next!=first)
        {

            printf("%d\t",current->data);
            current=current->next;
        }
        printf("%d",current->data);
    }

}

void destroy()
{

    struct Node *current,*follow;
    if(first==NULL)
        printf("empty");
    else
    {
        while(first!=NULL)
        {

            current=first;
            first=first->next;
            last->next=first;
            free(current);
        }

    }

}


void search()
{

    struct Node *pnode,*current;
    int x;
    printf("Enter the element to be found");
    scanf("%d",&x);
    while(current->data!=x && current!=NULL)
        current=current->next;
    if(current->data!=x)
        printf("Specified node not found");
    else
        printf("Specified node found");
}
void main()
{

    int choice;

    while(1)
    {

        printf("\n*******MENU*******\n");
        printf("1)create\n");
        printf("2)insertafter \n");
        printf("3)insertbefore");
        printf("4)delete \n");
        printf("5)traverse\n");
        printf("6)search\n");
        printf("7)DESTROY\n ");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);



        switch(choice)
        {

        case 1:
            create();
            break;

        case 2:
            insertafter();
            break;

        case 3:
            insertbefore();
            break;

        case 4:
            delete1();
            break;

        case 5:
            traverse();
            break;

        case 6:
            search();
            break;

        case 7:
            destroy();
            break;
        default:
            printf("\nInvalid input");
            }
    }
}
