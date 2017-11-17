#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<process.h>

#define NULL 0
struct node
{
	int data;
	struct node *next, *prev;

};
struct node *first=NULL,*last=NULL;
void create()
{
	char ch;
	struct node *pnode;
	do
	{
		pnode=(struct node*)malloc(sizeof (struct node));
		if (pnode == NULL)
		{
			printf("\n Cannot create node, Memory Overflow");
			exit(1);
		}
		else
		{
			printf("\n Enter data to be inserted");
			scanf("%d", &pnode->data);
			if(first == NULL)
			{
				pnode->next = pnode->prev = NULL;
				first = last = pnode;
			}
			else
			{
				pnode->next = NULL;
				pnode->prev = last;
				last->next = pnode;
				last = pnode;
			}
			printf("\n Do you want to Continue? (Y/N)" );
			scanf("%s", &ch);
		}
	}while(ch == 'y' || ch == 'Y');
}

void inserafter()
{
	int x;
	struct node *pnode,*current;

	if (first == NULL)
	{
		printf("\n Create DoublyLinkedList first");
		exit(1);
	}
	else
	{

		printf("\n Enter the data value after which pnode has to be inserted");
		scanf("%d",&x);
		/*Searching the requested node */
		current=first;
		while(current->data != x && current != NULL)
			current = current->next;
		if(current == NULL)
			printf("\n Specified node not found");
		else

		{
		    pnode=(struct node*)malloc(sizeof(struct node));
            printf("\n Enter the data to be inserted \n");
            scanf("%d", &pnode->data);
			if(current == last)
			{
				pnode->next = NULL;
				pnode-> prev= last;
				last->next = pnode;
				last = pnode;
			}
			else
			{
				pnode->prev = current;
				pnode->next = current->next;
				current->next->prev = pnode;
				current->next = pnode;
			}
		}
	}
}
void insertbefore()
{
	int x;
	struct node *pnode,*current;

	if (first == NULL)
	{
		printf("\n Create DLL first");
		exit(1);
	}
	else
	{

		printf("\n Enter the data value before which pnode has to be inserted");
		scanf("%d",&x);
		current = first;
		while(current->data != x && current != NULL)
			current = current->next;
		if(current == NULL)
			printf("\n Specified node not found");
		else
		{
		    pnode=(struct node*)malloc(sizeof(struct node));
		    printf("\n Enter the data value to be inserted");
            scanf("%d", &pnode->data);
			if(current == first)
			{
				pnode->prev = NULL;
				pnode->next = first;
				first->prev = pnode;
				first = pnode;
			}
			else
			{
				pnode->prev = current->prev;
				pnode->next = current;
				current->prev->next = pnode;
				current->prev=pnode;
			}
		}
	}
}
void deletenode()
{
	int x;
	struct node *current;
	printf("\n Enter the data item to be deleted");
	scanf("%d",&x);
	current = first;
	while(current->data != x && current != NULL)
		current = current->next;
	if(current == NULL)
		printf("\n Specified  node not found");
	else
	{
		if(current == first && current == last)
			first = last = NULL;
		else if (current == first)
		{
			first = first->next;
			first->prev = NULL;
		}
		else if (current == last)
		{
			last = last->prev;
			last->next = NULL;
		}
		else
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		free(current);
	}
}
void search()
{
	int x;
	struct node *pnode, *current;
	printf("\nEnter the data value of the node to be Searched: ");
	scanf("%d", &x);
	current = first;
	while(current->data != x && current !=NULL)
			current = current->next;
	if(current == NULL)
		printf("\nSpecified node not found");
	else
		printf("\nSpecified node found");
}
void destroylist()
{
	struct node *current;
	while(first != NULL)
	{
		current = first;
		first = first->next;
		free(current);
	}
	first = last = NULL;
}






