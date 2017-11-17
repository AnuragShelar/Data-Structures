#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define NULL 0
struct Node
{
    int data;
    struct Node *next,*prev;

};

struct Node *first=NULL,*last=NULL;

void create()
{
    char ch;
    struct Node *pnode;
    do
    {
        pnode=(struct Node*)malloc(sizeof(struct Node));
        if(pnode==NULL)
        {

            printf("\nCannot create Node memory overflow");
            exit(1);
        }
        else
        {

            pnode->next=NULL;
            pnode->prev=last;
            last->next=pnode;
            last=pnode;
        }
        printf("\nDo you wanna continue");
        scanf("%s",&ch);



    }while(ch=='Y'||ch=='y');
}

    void insertAfter()
    {
        int x;
        struct Node *pnode,*current;
        pnode=(struct Node*)malloc(sizeof(struct Node));
        if(pnode==NULL)
        {

            printf("\nCannot create node");
            exit(1);
        }
        else
        {

            printf("\nEnter data to be inserted ");
            scanf("%d",&pnode->data);
            printf("\nenter the data value after which node has to be inserted");
            scanf("%d",&x);

            current=first;
            while(current->data!=x && current!=NULL)
                current=current->next;
            if(current==NULL)
                printf("\nSpecified node not found");
            else
            {

                if(current==last)
                {

                    pnode->next=NULL;
                    pnode->prev=last;
                    last->next=pnode;
                    last=pnode;
                }
                else
                {

                    pnode->prev=current;
                    pnode->next=current->next;
                    current->next->prev=pnode;
                    current->next=pnode;

                }
            }
        }
    }

    void insertBefore()
    {

        int x;
        struct Node *pnode,*current;
        pnode=(struct Node*)malloc(sizeof(struct Node));
        if(pnode==NULL)
            printf("\nSpecified node not found");
        else
        {

            printf("\nEnter the data value to be inserted" );
            scanf("%d",&pnode->data);
            printf("\nEnter the data value before data has to be inserted");
            scanf("%d",&x);
            current=first;
            while(current->data!=x && current!=NULL)
                current=current->next;
            if(current==NULL)
            {
                printf("\nSpecified node not found");
            }
            else
            {

                if(current==first)
                {

                    pnode->prev=NULL;
                    pnode->next=first;
                    first->prev=pnode;
                    first=pnode;
                }
                else
                {

                    pnode->prev=current->prev;
                    pnode->next=current;
                    current->prev->next=pnode;
                    current->prev=pnode;
                }
            }
        }

    }


void deletenode()
{
    int x;
    struct Node *current;
    printf("\nEnter the data item to be deleted");
    scanf("%d",&x);
    current=first;
    while(current->data!=x &&current!=NULL)
        current=current->next;
    if(current==NULL)
        printf("\nSpecified node not found");
    else
    {

        if(current==first && current==last)
            first=last=NULL;
        else if(current==first)
        {

            first=first->next;
            first->prev=NULL;

        }
        else if(current==last)
        {
                last=last->prev;
                    last->next=NULL;


        }
        else
        {
            current->prev->next=current->next;
            current->next->prev=current->prev;

        }
        free(current);
    }

}
void search()
{

    int x;
    struct Node *pnode,*current;
    printf("\nEnter the data value to be searched");
    scanf("%d",&x);
    while(current->data!=x && current!=NULL)
        current=current->next;
    if(current->data!=x)
        printf("\nSpecified node not found");
    else
        printf("\nSpecified node found");

}



int main()
{

    int choice;
    do
    {
        printf("\n*****Doubly Circular Linked List*****\n");
        printf("\npress 1 for create");
        printf("\npress 2 for insertAFTER");
        printf("\npress 3 for insertBEFORE");
        printf("\npress 4 for delete");
        printf("\npress 5 for exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {

        case 1:
            create();
            break;

        case 2:
            insertAfter();
            break;
        case 3:
            insertBefore();
            break;

        case 4:
            deletenode();
            break;
        case 5:
            search();
            break;

        default:
            printf("\nInvalid input");
        }
}while(choice!=5);
return 0;
}
