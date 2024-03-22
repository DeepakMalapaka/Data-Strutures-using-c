#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
void search(struct node *,int );
void search(struct node *tail,int key)
{
 struct node *ptr=tail->next;
 int count=0;
 while(ptr!=NULL)
 {
  count++;
  if(key==ptr->data)
  {
   printf("Data is found at %d\n",count);
   return;
  }
  ptr=ptr->next;
 }
 printf("Data is not found\n");
 return;
}
int count_of_nodes(struct node *tail);
int count_of_nodes(struct node *tail)
{
 int count=0;
 struct node *temp=tail->next;
 while(temp!=tail)
 {
  temp=temp->next;
  count++;
 }
 return count;
}
struct node * create_node(int );
struct node * create_node(int d)
{
 struct node *temp=malloc(sizeof(struct node *));
 temp->data=d;
 temp->next=NULL;
 return temp;
}
void display(struct node *);
void display(struct node *tail)
{
 if(tail==NULL)
 {
  printf("List is empty\n");
  return;
 }
 struct node *temp;
 temp=tail->next;
 do
 {
  printf("%d ",temp->data);
  temp=temp->next;
 }while(temp!=tail->next);
 printf("\n");
}
void insert_at_beginnig(struct node *,int );
void insert_at_beginning(struct node *tail,int d)
{
 if(tail==NULL)
 {
  printf("List is empty\n");
  return;
 }
 struct node *temp=create_node(d);
 temp->next=tail->next;
 tail->next=temp;
 
}
void insert_at_end(struct node **,int );
void insert_at_end(struct node **tail,int d)
{
 if(tail==NULL)
 {
  printf("List is empty\n");
  return;
 }
 struct node *temp=create_node(d);
 temp->next=(*tail)->next;
 (*tail)->next=temp;
 (*tail)=temp;
}
void insert_at_position(struct node *,int ,int ,int );
void insert_at_position(struct node *tail,int d,int pos,int size)
{
 if(pos<1||pos>size+1)
 {
  printf("Invalid position\n");
  return;
 }
 if(pos==1)
 {
  insert_at_beginning(tail,d);
  return;
 }
 if(pos==size+1)
 {
  insert_at_end(&tail,d);
  return;
 }
 if(tail==NULL)
 {
  printf("List is empty\n");
  return;
 }
 struct node *temp=create_node(d);
 struct node *ptr=tail->next;
 pos--;
 while(pos!=1)
 {
  ptr=ptr->next;
  pos--;
 }
 temp->next=ptr->next;
 ptr->next=temp;
}
void delete_at_beginning(struct node *);
void delete_at_beginning(struct node *tail)
{
 struct node *temp=tail->next;
 tail->next=temp->next;
 free(temp);
}
void delete_at_end(struct node **tail);
void delete_at_end(struct node **tail)
{
 struct node *temp=(*tail)->next;
 while(temp->next!=(*tail))
 {
  temp=temp->next;
 }
 temp->next=(*tail)->next;
 struct node *ptr=(*tail);
 (*tail)=temp;
 free(ptr);
}
void delete_at_postion(struct node *,int ,int);
void delete_at_position(struct node *tail,int pos,int size)
{
 if(pos<1||pos>size+1)
 {
  printf("Invalid position\n");
  return;
 }
 if(pos==1)
 {
  delete_at_beginning(tail);
  return;
 }
 if(pos==size+1)
 {
  delete_at_end(&tail);
  return;
 }
 if(tail==NULL)
 {
  printf("List is empty\n");
  return;
 }
 struct node *ptr=tail->next;
 pos--;
 while(pos!=1)
 {
  ptr=ptr->next;
  pos--;
 }
 struct node *temp=ptr->next;
 struct node *ptr1=temp->next;
 ptr->next=ptr1;
 free(temp);
}														
int main() 
{
 struct node *tail=malloc(sizeof(struct node *));
 tail->data=10;
 tail->next=tail;
 insert_at_beginning(tail,20);
 insert_at_beginning(tail,30);
 display(tail);
 printf("After inserting at beginning\n");
 insert_at_beginning(tail,40);
 display(tail);
 printf("After inserting at end\n");
 insert_at_end(&tail,50);
 display(tail);
 printf("After inserting at position\n");
 insert_at_position(tail,60,2,count_of_nodes(tail));
 display(tail);
 printf("After deleting at position\n");
 delete_at_position(tail,2,count_of_nodes(tail));
 display(tail);
 printf("After deleting at beginning\n");
 delete_at_beginning(tail);
 display(tail);
 printf("After deleting at end\n");
 delete_at_end(&tail);
 display(tail);
 int key;
 printf("Enter a value to search in single circular linked list:");
 scanf("%d",&key);
 search(tail,key);
 return 0;
}
