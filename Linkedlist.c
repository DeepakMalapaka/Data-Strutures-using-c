#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
int count_of_nodes(struct node *);
int count_of_nodes(struct node *head)
{
	int count;
	while(head!=NULL)
	{
		head=head->next;
		count++;
	}
	return count;
}
void display(struct node *);
void display(struct node *head)
{
	struct node *t=head;
	while(t!=NULL)
    {
     printf("%4d",t->data);
     t=t->next;
    } 
    printf("\n");
}
void insert_at_beginning(struct node **,int );
void insert_at_beginning(struct node **head,int x)
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	struct node *temp=malloc(sizeof(struct node *));
	temp->data=x;
	temp->next=NULL;
	temp->next=*head;
	*head=temp;
}

void insert_at_end(struct node *,int );
void insert_at_end(struct node *head,int x) 
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	struct node *ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
}
void insert_at_position(struct node *,int ,int,int);
void insert_at_position(struct node *head,int pos,int x,int size)
{
	if(head==NULL)
	{
		printf("List is empty");
	}
	else if(pos<1)
	{
		printf("Invalid position");
	}
	else if(pos==1)
	{
		insert_at_beginning(&head,x);
	}
	else if(pos>=size)
    {
      insert_at_end(head,x);
    }
	else
	{
		struct node *temp=malloc(sizeof(struct node *));
		temp->data=x;
		temp->next=NULL;
		struct node *ptr=malloc(sizeof(struct node *));
		ptr=head;
		pos--;
		while(pos!=1)
		{
			ptr=ptr->next;
            pos--;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
void printing_of_nodes(struct node *,int *);
void printing_of_nodes(struct node *head,int *size)
{
 display(head);
 *size=count_of_nodes(head);
 printf("Number of nodes:%d\n",*size);
}
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
  int size=count_of_nodes(head);
 printing_of_nodes(head,&size);
 insert_at_beginning(&head,60);
 printf("After inserting at beginning\n");
 printing_of_nodes(head,&size);
 insert_at_position(head,5,70,&size);
 printf("After inserting at position\n");
 printing_of_nodes(head,&size);
 insert_at_end(head,50); 
 printf("After inserting at end\n");
 printing_of_nodes(head,&size);
 return 0; 
}
