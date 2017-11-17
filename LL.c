#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>


struct Node
{
    int data;
    struct Node *next;

};

struct Node *first=NULL,*last=NULL;

void create()
{
    char choice;
    struct Node *pnode,*current,*follow;
    do
    {
        pnode=(struct Node *)malloc(sizeof(struct Node));
        printf("\nenter the data to be inserted: ");
        scanf("%d",&pnode->data);
        pnode->next=NULL;

        if(first==NULL)
            first=pnode;
        else
            last->next=pnode;

        last=pnode;
        printf("\nDo you want to add another node?PRESS Y or y: ");
        scanf("%s",&choice);


    }while(choice=='Y' || choice=='y');
}


void InsertAfter()
{
    int x;
    struct Node *pnode,*current,*follow;
    if(first==NULL)
        printf("\nCREATE LINKED LIST... ");
    else
    {
        pnode=(struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the data value of node: ");
        scanf("%d",&pnode->data);
        printf("\nenter the node after which node has to be inserted: ");
        scanf("%d",&x);

        current=first;
        while(current!=NULL && current->data!=x)
            current=current->next;
        if(current==NULL)
            printf("%d node not found",x);
        else
        {
            pnode->next=current->next;
            current->next=pnode;

        }
        printf("\nNode inserted successfully....");
    }
}

void InsertBefore()
{
    int x;
    struct Node *pnode,*current,*follow;
    if(first==NULL)
        printf("\nCREATE LINKED LIST... ");
    else
    {
        pnode=(struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the data value of node: ");
        scanf("%d",&pnode->data);
        printf("\nenter the node before which node has to be inserted: ");
        scanf("%d",&x);

        current=first;
        follow=NULL;
        while(current!=NULL && current->data!=x)
        {
            follow=current;
            current=current->next;
        }
        if(current==NULL)
            printf("%d node not found",x);
        else
        {
            pnode->next=follow->next;
            follow->next=pnode;

        }
        printf("\nNode inserted successfully....");
    }
}
void search()
{
    int x;
    struct Node *current,*follow;
    printf("\nenter the data to be searched: ");
    scanf("%d",&x);
    current=first;

    while(current!=NULL && current->data!=x)
        current=current->next;

    if(current==NULL)
        printf("\n node with data %d not found",x);
    else
        printf("\nnode with %d node found",x);
}

void del()
{
    int x;
    struct Node *current,*follow;
    printf("\nenter the data to be deleted: ");
    scanf("%d",&x);
    current=first;
    follow=NULL;

    while(current!=NULL && current->data!=x)
    {
        follow=current;
        current=current->next;
    }
    if(current==NULL)
        printf("%d node not found",x);
    else
    {
        if(current==first)
            first=first->next;
        else
            follow->next=current->next;

        free(current);
        printf("Node deleted successfully...");
    }
}

void InsertPosition()
{
    struct Node *pnode,*current;
    int p,i;
    if(first==NULL)
        printf("\nCannot be inserted...");
    else
    {
        printf("\nenter the position at which data has to be inserted: ");
        scanf("%d",&p);
        pnode=(struct Node *)malloc(sizeof(struct Node));
        printf("\nenter the data to be inserted: ");
        scanf("%d",&pnode->data);
        if(p==1)
        {
            pnode->next=first;
            first=pnode;
        }
        current=first;
        for(i=1;i<p-2;i++)
            current=current->next;
        pnode->next=current->next;
        current->next=pnode;

    }

}


void display()
{

    struct Node *current;
    if(first==NULL)
        printf("\nLIST IS EMPTY");
    else
    {
        printf("\nLINKED LIST IS..");
        current=first;

        while(current!=NULL)
        {
            printf("%d\t",current->data);
            current=current->next;
        }
}

}
void main()
{

    int choice;
    do
    {
        printf("\n****SNGLY LINKED LIST*****\n");
        printf("\n1)Create a LINKED LIST");
        printf("\n2)Insert after element");
        printf("\n3)Insert before element");
        printf("\n4)Delete a element");
        printf("\n5)Search an element");
        printf("\n6)Display LINKED LIST");
        printf("\n7)Insert  at position:");
        printf("\nEnter your choice:  ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            InsertAfter();
            break;
        case 3:
            InsertBefore();
            break;
        case 4:
            del();
            break;
        case 5:
            search();
           break;
        case 6:
            display();
            break;
        case 7:
            InsertPosition();
            break;

        case 8:
            exit(1);
        default:
            printf("\nInvalid input\n");
            break;
        }

    }while(choice!=8);
}
