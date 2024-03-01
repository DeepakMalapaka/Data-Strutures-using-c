#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
int main() 
{
 struct node *head;
  head=malloc(sizeof(struct node));
  head->data=10;
  head->next=NULL;
 
 struct node *current;
  current=malloc(sizeof(struct node));
  current->data=20;
  head->next=current;
  current->next=NULL;
 struct node *current1;
  current1=malloc(sizeof(struct node));
  current1->data=30;
  current->next=current1;
  current1->next=NULL;
 struct node *current2;
  current2=malloc(sizeof(struct node));
  current2->data=40;
  current1->next=current2;
  current2->next=NULL;
 struct node *t=head; 
 while(t!=NULL)
 {
  printf("%4d",t->data);
  t=t->next;
 } 
 return 0; 
}
