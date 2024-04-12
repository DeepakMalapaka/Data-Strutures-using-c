#include<stdio.h>
#define max 100

int a[max],top;
void push(int ,int);
void push(int d,int size)
{
 if(top>=size-1)
 {
  printf("Stack is overflow\n");
  return;
  
 }
 top++;
 a[top]=d;
}
void display(int );
void display(int top)
{
 while(top!=-1)
 {
  printf("%d  ",a[top]);
  top--;
 }
 printf("\n");
}
void pop();
void pop()
{
 printf("The poped element is:%d\n",a[top]);
 top--;
}
int main ()
{
 int size;
 printf("Enter the size of stack array:");
 scanf("%d",&size);
 top=-1;
 push(10,size);
 push(20,size);
 push(30,size);
 push(40,size);
 push(50,size);
 display(top);
 pop();
 pop();
 pop();
 return 0;
}
