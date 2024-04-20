#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char infix[max],postfix[max],stack[max];
int top=-1;
int isFull()
{
	if(top==max-1)
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
	if(isFull())
	{
		printf("Stack is overflow\n");
		exit(1);
	}
	top++;
	stack[top]=x;
	
	return ;
} 
char pop(void );
char pop(void )
{
	if(isEmpty())
	{
		printf("Stack is underflow\n");
	}
	char character;
	character=stack[top];
	top--;
	return character;
}
int precedence(char );
int precedence(char symbol)
{
	switch(symbol) {
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 2;
	case '^':return 3;
	default :return 0;
      }	
}
void infix_to_postfix(void );
void infix_to_postfix(void )
{
	int i,j=0;
	for(i=0;infix[i]!='\0';i++)
	{
		char symbol=infix[i],next;
		
		switch(symbol) {
		case '(':push(symbol);
			 break;
		case ')':while((next=pop())!='(')
				postfix[j++]=next;
			break;
		case '^':
		case '+':
		case '-':
		case '*':
		case '/':while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
				postfix[j++]=pop();			
			push(symbol);
			break;
		default :postfix[j++]=symbol;
			 break;
		}
		
	}
	while(top!=-1)
	{
		//char character=pop();
		postfix[j++]=pop();
		postfix[j]='\0';
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
void postfix_evalute(void )
{
	int a,b,i;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
			push(postfix[i]-'0');
		else 
		{
			a=pop()-'0';
			b=pop()-'0';
			switch(postfix[i])
			{
				case '+':push(b+a);
					break;
				case '-':push(b-a);
					break;
				case '*':push(b*a);
					break;
				case '/':push(b/a);
					break;
				case '^':push(b^a);
					break;
				
			}
		}
	}
	push('\0');
}
int main()
{
	printf("Enter an infix expression:");
	scanf("%s",infix);
	printf("The infix expression is :");
	display(infix);
	infix_to_postfix();
	printf("The post fix expression is :");	display(postfix);
	postfix_evalute();
	display(int (stack));
	return 0;
}
