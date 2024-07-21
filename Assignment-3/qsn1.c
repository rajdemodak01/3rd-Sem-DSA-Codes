// write a C program to convert a given infix expression  to postfix expression. 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max_size 100
char s[max_size];
int top = -1;
void push(int n)
{
	if (top == max_size - 1)
	{
		printf("Stack is overflown");
		exit(0);
	}
	else
	{
		top++;
		s[top] = n;
	}
}
int pop()
{
	int a;
	if (top == -1)
	{
		printf("Stack is underflown");
		exit(0);
	}
	else
	{
		a = s[top];
		top--;
	}
	return a;
}
int preference(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}
void conversion(char infix[], char postfix[])
{
	int i = 0, j = 0;
	while (infix[i] != '\0')
	{
		if (isalnum(infix[i]))
		{
			postfix[j] = infix[i];
			i++, j++;
		}
		else if (infix[i] == '(')
		{
			push(infix[i]);
			i++;
		}
		else if (infix[i] == ')')
		{
			while (top != -1 && s[top] != '(')
			{
				postfix[j] = pop();
				j++;
			}
			pop();
			i++;
		}
		else
		{
			while (preference(infix[i]) < preference(s[top]))
			{
				postfix[j] = pop();
				j++;
			}
			push(infix[i]);
			i++;
		}
	}
	postfix[j] = '\0';
}
int main()
{
	char infix[max_size], postfix[max_size];
	printf("Enter Infix:\n");
	fgets(infix, max_size, stdin);
	conversion(infix, postfix);
	printf("After converting from infix to postfix:\n");
	printf("%s\n", postfix);

	return 0;
}
