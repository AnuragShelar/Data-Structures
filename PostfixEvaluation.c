#include<stdio.h>
#include<conio.h>
#include<string.h>

//REQUIRE MACRO
#define MAX 100
#define OPERAND 10
#define OPERATOR 20

struct stack
{
	int top;
	int items[MAX];
};

void push(struct stack *ps, int x)
{
	ps->items[++ps->top] = x;
}
int pop(struct stack *ps)
{
	return(ps->items[ps->top--]);
}
int get_type(char sym)
{
	switch(sym)
	{
		case '+':
		case '-':
		case '*':
		case '%':
		case '/':
				return(OPERATOR);
		default: return(OPERAND);
	}
}
void eval(struct stack *ps, char op, int num1 , int num2)
{
	int res;
	switch(op)
	{
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num1 - num2;
			break;
		case '*':
			res = num1 * num2;
			break;
		case '/':
			res = num1 / num2;
			break;
		case '%':
			res = num1 % num2;
			break;
		case '^':
			res = pow(num1, num2);
			break;
	}
	push(ps, res);
}
void main()
{
	char pos[MAX];
	int num1, num2, item, l, i, pr;
	struct stack s;

	s.top = -1;
	printf("\nEnter the postfix expression: ");
	gets(pos);
	for(i=0; pos[i]!= '\0'; i++)
	{
		switch(get_type(pos[i]))
		{
			case OPERAND:
				item = pos[i] - '0';
				push(&s, item);
				break;
			case OPERATOR:
				num1 = pop(&s);
				num2 = pop(&s);
				eval(&s, pos[i], num2, num1);
		}
	}
	printf("%d", s.items[s.top]);

}





