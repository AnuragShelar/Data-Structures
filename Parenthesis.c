#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
void push(char);
char pop();

#define MS 100
char stack[MS];
int top=-1;

void push(char s)
{
    if(top==MS-1)
        printf("\nOverflow...");
    else
    {
        top++;
        stack[top]=s;
    }
}

char pop()
{
    char temp;
    if(top==-1)
        printf("Underflow...");

    else
    {
        temp=stack[top];
        top--;
        return temp;
    }

}
int main()
{
    char s[MS],temp;
    int i,flag=1;

    printf("\nEnter an expression");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {

        if(s[i]=='('|| s[i]=='{' || s[i]=='[')
            push(s[i]);
        if(s[i]==')'|| s[i]=='}' || s[i]==']')
       {
            if(top==-1)
                flag=0;
            else
            {
                    temp=pop();
                    if(s[i]==')' && (temp=='[' || temp=='{'))
                        flag=0;
                      if(s[i]==']' && (temp=='(' || temp=='{'))
                        flag=0;
                     if(s[i]=='}' && (temp=='[' || temp=='('))
                        flag=0;

            }
        }
       }


            if(top>=0)
                flag=0;
            if(flag==0)
                printf("NO");
            else
                printf("YES");
            return  0;

}








