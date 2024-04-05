#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};
void search(struct node *,int );
void search(struct node *tail,int key)
{
	struct node *ptr=tail->next;
	int count=0;
	while(ptr!=tail)
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
void display(struct node *);
void display(struct node *tail)
{
	struct node *temp;
	temp=tail->next;
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=tail->next);
	printf("\n");
}
struct node * create_node(int );
struct node * create_node(int d)
{
	struct node *temp=malloc(sizeof(struct node *));
	temp->data=d;
	temp->next=temp;
	temp->prev=temp;
	return temp;
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
void insert_at_beginning(struct node *,int );
void insert_at_beginning(struct node *tail,int d)
{
	if(tail==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct node *temp=create_node(d);
	struct node *ptr=tail->next;
	temp->prev=tail;
	tail->next=temp;
	ptr->prev=temp;
	temp->next=ptr;
}
void insert_at_end(struct node **,int);
void insert_at_end(struct node **tail,int d)
{
	struct node *temp=create_node(d);
	struct node *ptr=(*tail)->next;
	temp->next=(*tail)->next;
	temp->prev=(*tail);
	(*tail)->next=temp;
	(*tail)=temp;
	ptr->prev=(*tail);
}
void insert_at_position(struct node *,int ,int ,int);
void insert_at_position(struct node *tail,int d,int pos,int size)
{
	if(tail==NULL)
	{
		printf("List is empty\n");
		return;
	}
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
	struct node *temp=create_node(d);
	struct node *ptr=tail->next;
	pos--;
	while(pos!=1)
	{
		ptr=ptr->next;
		pos--;
	}
	struct node *ptr1=ptr->next;
	temp->prev=ptr;
	temp->next=ptr1;
	ptr->next=temp;
	ptr1->prev=temp;
	return;
}
void delete_at_beginning(struct node *);
void delete_at_beginning(struct node *tail)
{
	struct node *ptr=tail->next;
	struct node *ptr1=ptr->next;
	tail->next=ptr1;
	ptr1->prev=tail;
	free(ptr);
}
void delete_at_end(struct node **);
void delete_at_end(struct node **tail)
{
	struct node *ptr=(*tail)->prev;
	struct node *ptr1=(*tail)->next;
	struct node *temp=(*tail);
	ptr->next=ptr1;
	ptr1->prev=ptr;
	(*tail)=ptr;
	free(temp);
	return;
}
void delete_at_position(struct node *,int ,int );
void delete_at_position(struct node *tail,int pos,int size)
{
	if(tail==NULL)
	{
		printf("List is empty\n");
		return;
	}
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
	pos--;	
	struct node *ptr=tail->next;
	while(pos!=1)
	{
		ptr=ptr->next;
		pos--;
	}
	struct node *temp=ptr->next;
	struct node *ptr1=temp->next;
	ptr->next=ptr1;
	ptr1->prev=ptr;
	free(temp);
}
int main() 
{
	struct node *tail=malloc(sizeof(struct node *));
	tail->data=10;
	tail->next=tail;
	tail->prev=tail;
	insert_at_beginning(tail,20);
	insert_at_beginning(tail,30);
	display(tail);
	insert_at_beginning(tail,40);
	display(tail);
	insert_at_end(&tail,50);
	display(tail);
	insert_at_position(tail,60,2,count_of_nodes(tail));
	display(tail);
	delete_at_position(tail,2,count_of_nodes(tail));
	display(tail);
	delete_at_beginning(tail);
	display(tail);
	delete_at_end(&tail);
	display(tail);
	search(tail,20);
	return 0;
}
