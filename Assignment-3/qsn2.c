#include <stdio.h>
// if there is an expression than take two top from the stack and perform the operation in betweeen them
int stack[100], top = -1;

void push(int a){
	 stack[++top] = a;
}

int pop() { 
	return stack[top--]; 
}
int main()
{
	// take the input but for now we will give the input ourselves 562+*124/-
	char arr[100];
	scanf("%[^\n]%*c", arr);

	int n = 0, digit = 0, places = 1, number = 0;
	while (arr[n] != 0)
	{
		switch (arr[n])
		{
			case '+':
				int a = pop(), b = pop();
				push(b + a);
				break;
			case '-':
				int a = pop(), b = pop();
				push(b - a);
				break;
			case '*':
				int a = pop(), b = pop();
				push(b * a);
				break;
			case '/':
				int a = pop(), b = pop();
				push(b / a);
				break;
			case ' ':
				places = 1;
				number = 0;
				for (int i = 1; i <= digit; i++)
				{
					number = number + (arr[n - i] - '0') * places;
					places = places * 10;
				}
				if (digit != 0)
				{
					push(number);
					digit = 0;
				}
				break;
			default:
				digit++;
				break;
		}
		n++;
	}
	for (int i = top; i >= 0; i--)
	{
		printf("%d\t", stack[i]);
	}
	printf("\n");
	return 0;
}
