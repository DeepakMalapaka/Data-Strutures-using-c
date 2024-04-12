#include<stdio.h>
#include<stdlib.h>
struct node 
{
 int data;
 struct node *next;
}*top=NULL;
struct node * create_node(int d);
struct node * create_node(int d)
{
 struct node *temp=malloc(sizeof(struct node *));
 temp->data=d;
 temp->next=NULL;
 return temp;
}
void push(int );
void push(int d)
{
 struct node *temp=create_node(d);
 temp->next=top;
 top=temp;
}
void display();
void display()
{
 if (top==NULL)
 {
  printf("List is under flow ");
  return ;
 }
 struct node *temp=top;
 while(temp!=NULL)
 {
  printf("%4d",temp->data);
  temp=temp->next;
 }
 printf("\n");
}
int pop();
int pop()
{
 int d;
 struct node *temp=top;
 d=top->data;
 top=top->next;
 free(temp);
 return d;
}
int main()
{
 push(10);
 push(20);
 push(30);
 display();
 printf("The poped element is :%d\n",pop());
 int x;
 
 return 0;
}
