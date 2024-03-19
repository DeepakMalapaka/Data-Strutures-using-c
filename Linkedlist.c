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
	int count=0;
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
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
	else if(pos<1||pos>size+1)
	{
		printf("Invalid position\n");
	}
	else if(pos==1)
	{
		insert_at_beginning(&head,x);
	}
	else if(pos==size)
    	{
      		insert_at_end(head,x);
    	}
	else
	{
		struct node *temp=malloc(sizeof(struct node *));
		temp->data=x;
		temp->next=NULL;
		struct node *ptr=head;
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
void delete_at_end(struct node *);
void delete_at_end(struct node *head)
{
 struct node *ptr=head;
 struct node *current;
 while(ptr->next!=NULL)
 {
  current=ptr;
  ptr=ptr->next;
 }
 current->next=NULL;
 free(ptr);
}
void delete_at_beginning(struct node **);
void delete_at_beginning(struct node **head)
{
 struct node *ptr=*head;
 (*head)=(*head)->next;
 free(ptr);
}
void delete_at_position(struct node *,int ,int);
void delete_at_position(struct node *head,int pos,int size)
{
         if(head==NULL)
	{
		printf("List is empty");
	}
	else if(pos<1||pos>size+1)
	{
		printf("Invalid position\n");
	}
	else if(pos==1)
	{
		delete_at_beginning(&head);
	}
	else if(pos==size)
    	{
      		delete_at_end(head);
    	}
	else
	{
		struct node *ptr=head;
		struct node *temp=head;
		while(pos!=1)
		{
		 ptr=ptr->next;
		 pos--;
		}	
		temp->next=ptr->next;
		free(ptr);
	}
}
void printing_of_nodes(struct node *);
void printing_of_nodes(struct node *head)
{
 int size;
 display(head);
 size=count_of_nodes(head);
 printf("Number of nodes:%d\n",size);
}
void search(struct node *,int );
void search(struct node *head,int key)
{
 int count=0;
 struct node *ptr=head;
 while(ptr!=NULL)
 {
   count++;
   if(key==ptr->data)
   {
    printf("Key is found at position %d",count);
    return;
   }
   ptr=ptr->next;
 }
 printf("**Key is not found**\n");
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
 printing_of_nodes(head);
 insert_at_beginning(&head,50);
 printf("After inserting at beginning\n");
 printing_of_nodes(head);
 insert_at_position(head,5,60,count_of_nodes(head));
 printf("After inserting at position\n");
 printing_of_nodes(head);
 insert_at_end(head,70);
 printf("After inserting at end\n" );
 printing_of_nodes(head);
 delete_at_end(head);
 printf("After deleting at end\n");
 printing_of_nodes(head); 
 delete_at_beginning(&head);
 printf("After deleting at beginning\n");
 printing_of_nodes(head);
 delete_at_position(head,5,count_of_nodes(head));
 printf("After deleting at postion\n");
 printing_of_nodes(head);
 int key;
 printf("Enter a element to search ");
 scanf("%d",&key);
 search(head,key);
 return 0; 
}
