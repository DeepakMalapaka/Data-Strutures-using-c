#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char infix[max],postfix[max],stack[max];
int top=-1;
int isFull()
{
	if(top=strlen(infix))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
void push(char );
void push(char x)
{
	top++;
	stack[top]=x;
	if(isFull())
	{
		printf("Stack is overflow\n");
	}
	return ;
} 
char pop(void );
char pop(void )
{
	
	char character;
	character=stack[top];
	top--;
	if(isEmpty())
	{
		printf("Stack is underflow\n");
	}
	return character;
}
int precedence(char );
int precedence(char symbol)
{
	switch(symbol) {
	case '(':return 0;
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 2;
	case '^':return 3;
      }	
}
void infix_to_postfix(void );
void infix_to_postfix(void )
{
	int i,j=-1;
	for(i=0;infix[i]!='\0';i++)
	{
		char symbol=infix[i],next;
		if(symbol>='0'&& symbol<='9')
		{
			postfix[j++]=symbol;
			return ;
		}
		switch(symbol) {
		case '(':push(symbol)
			 break;
		case ')':while((next=pop())!='(')
				postfix[j++]=next;
			break;
		case '+':
		case '-':
		case '*':
		case '/':while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
			{
				postfix[j++]=pop();			
				push(symbol);
			}
			break;
		}
		
	}
	while(top!=-1)
	{
		char character=pop();
		postfix[j++]=character;
	}
}
void display(char [max]);
void display(char string[max])
{
	int i;
	for(i=0;string[i]!='\0';i++)
	{
		printf("%c",string[i]);
	}
	printf("\n");
}
int main()
{
	printf("Enter an infix expression:");
	scanf("%s",infix);
	infix_to_postfix();
	display(postfix);
	return 0;
}
