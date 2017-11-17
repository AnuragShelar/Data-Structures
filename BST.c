#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
    int data;
    struct node *left,*right;

};

struct node *root=NULL;
int ncount,lcount;

void create()
{

    int n,x,i;
    printf("\nenter the no of nodes you want to create");
    scanf("%d",&n);
    printf("\nenter the data value of node:  ");
    for(i=0;i<n;i++)
    {

        scanf("%d",&x);
        insert(x);
    }
}

void insert(int x)
{

    struct node *pnode,*current,*follow;
    pnode=(struct node*)malloc(sizeof(struct node)) ;

    if(pnode==NULL)
        printf("\nMemory overflow..");
    else
    {
        pnode->data=x;

        pnode->right=pnode->left=NULL;

        if(root==NULL)
            root=pnode;
        else
        {
            current=root;
            follow=NULL;
                while(current!=NULL)
                {
                    follow=current;
                    if(pnode->data<current->data)
                        current=current->left;
                    else
                        current=current->right;

                }

            if(pnode->data<follow->data)
                follow->left=pnode;
            else
                follow->right=pnode;


        }


    }
}

void preorder(struct node *root)
{

    if(root!=NULL)
    {

        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{

    if(root!=NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);

    }
}
void inorder(struct node *root)
{

    if(root!=NULL)
    {

        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);


    }
}

void deletenode(int k)
{

    struct node *current,*follow,*t,*f;
    current=root;
    follow=NULL;

    while(current!=NULL && current->data!=k)
    {

        follow=current;
        if(k<current->data)
            current=current->left;
        else
            current=current->right;
    }
    if(current==NULL)
        printf("required Node not found");
    else
    {
        if(current->left==NULL){
            if(current!=root)
                    if(follow->left==current)
                            follow->left=current->right;
                    else
                        follow->right=current->right;
            else
                root=current->right;
        }

        else if(current->right==NULL){
             if(current!=root)
                    if(follow->left==current)
                            follow->left=current->left;
                    else
                        follow->right=current->left;
            else
                root=current->left;
        }

                else
            {
                t = current->right ;
                f = current ;
                while(t->left!=NULL)
                {
                    f = t ;
                    t = t->left ;
                }

                current->data = t->data ;
                if(f != current)
                    f->left = t->right ;
                else
                    f->right = t->right;

                current = t ;

            }
		free(current);
    }

}

void search(int k)
{

    struct node *current,*follow;
    current=root;
    follow=NULL;

    while(current!=NULL && current->data!=k)
    {

        follow=current;
        if(k<current->data)
            current=current->left;
        else
            current=current->right;
    }
    if(current==NULL)
        printf("Required node not found");
    else
        printf("Required node found");
}

void nodecount(struct node *root)
{

    if(root!=NULL)
    {
        nodecount(root->left);
        ++ncount;
        nodecount(root->right);
    }
}

void leafcount(struct node *root)
{
    struct node *current;

    if(root!=NULL)
    {

        leafcount(root->left);
        while(current->left==NULL && current->right==NULL)
        {
            ++lcount;
            printf("%d",root->data);


        }
        leafcount(root->right);
    }
}

void smallestnode()
{
    struct node *current;
    if(root==NULL)
        printf("TREE EMPTY");
    else
    {

        current=root;
        while(current->left!=NULL)
            current=current->left;
        printf("Smallest node is %d",current->data);
    }
}


void largestnode()
{
    struct node *current;
    if(root==NULL)
        printf("TREE EMPTY");
    else
    {

        current=root;
        while(current->right!=NULL)
            current=current->right;
        printf("Smallest node is %d",current->data);
    }
}

void main()
{
  int  x , k , ch ;



  do
  {
    printf("1.Create. \n") ;
    printf("2.Insert. \n") ;
    printf("3.Preorder. \n") ;
    printf("4.Inorder. \n") ;
    printf("5.Postorder. \n") ;
    printf("6.Delete Node. \n") ;
    printf("7.Search \n") ;
    //printf("8.Level Node. \n") ;
    printf("9.Node Count. \n") ;
    printf("10.Leaf Count. \n") ;
    printf("11.Find smallest\n") ;
    printf("12.Find Largest\n") ;
    printf("13.Exit\n") ;

    printf("Enter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      create() ;
      break ;

      case 2:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      insert(x) ;
      break ;

      case 3:
      preorder(root) ;
      printf("\n") ;
      break ;

      case 4:
      inorder(root) ;
      printf("\n") ;
      break ;

      case 5:
      postorder(root) ;
      printf("\n") ;
      break ;

      case 6:
      printf("Enter data of the node to be deleted: ") ;
      scanf("%d",&k) ;
      deletenode(k) ;
      break ;

      case 7:
      printf("Enter data of the node to be searched: ") ;
      scanf("%d",&k) ;
      search(k) ;
      break ;

     /* case 8:
      printf("Enter data of the node whose level is to be found: ") ;
      scanf("%d",&k) ;
      levelnode(k) ;
      break ;*/

      case 9:
      ncount=0 ;
      nodecount(root) ;
      printf("No. of nodes present in the tree are %d \n",ncount) ;
      break ;

      case 10:
      lcount=0 ;
      leafcount(root) ;
      printf("No. of Leaf nodes present in the tree are %d \n",lcount) ;
      break ;

      case 11:
        smallestnode() ;
      break ;

      case 12:
      largestnode() ;
      break ;
    }
  }
  while(ch!=13) ;


}








