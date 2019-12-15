#include<stdio.h>
#include<malloc.h>
struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
}tree;

tree* BST(tree* root,int data)
{
	if(root==NULL)
	{
		tree* temp = (tree*)malloc(sizeof(tree));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else if(data < root->data)
	{
		root->left = BST(root->left,data);
	}
	else if(data > root->data)
	{
		root->right = BST(root->right,data);
	}
	return root;
}

// queue
struct node
{
	struct tree* data;
	struct node* next;
};
struct queue
{
	struct node* front;
	struct node* rear;
};
struct node* newNode(int d)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	temp->next = NULL;
	return temp;
}
struct queue* create()
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->front=NULL;
	q->rear=NULL;
	return q;
}
void push()
{
	
}

