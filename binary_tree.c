#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node * create_node(int );
struct node * create_node(int d)
{
	struct node *temp=malloc(sizeof(struct node *));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp; 
}
struct node * insert(struct node *,int );
struct node * insert(struct node *root,int d)
{
	if(root==NULL)
	{
		return create_node(d);
	}
	if(d<root->data)
	{
		root=insert(root->left,d);
	}
	if(d>root->data)
	{
		root=insert(root->right,d);
	}
	return root;
}
void Inorder(struct node *);
void Inorder(struct node *root)
{
	if(root->left!=NULL)
	{
		Inorder(root->left);
	}
	printf("%4d",root->data);
	if(root->right)
	{
		
	}
}
int main()
{
	struct node *root;
	root=insert(root,50);
	root=insert(root,20);
	
	return 0;
}
