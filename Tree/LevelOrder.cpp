#include<stdio.h>
#include<malloc.h>
typedef struct tree
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

//queue
typedef struct node
{
	tree* data;
	struct node* next;
}node;

typedef struct queue
{
	node* front;
	node* end;
}queue;

void push(queue* q,tree* data)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	new_node->data = data;
	
	if(q->end == NULL)
	{
		q->end = new_node;
		q->front = new_node;
	}
	else
	{
		q->end->next = new_node;
		q->end = new_node;
	}
}

int isEmpty(queue* q)
{
	if(q->end == NULL)
		return 1;
	return 0;
}

tree* top(queue* q)
{
	tree* temp = q->front->data;
	return temp;
}
void pop(queue* q)
{
	if(q->front->next)
	{
		q->front = q->front->next;
	}
	else
	{
		q->front = NULL;
		q->end = NULL;
	}
}

// function
void level_order(tree* root)
{
	printf("this is level order function\n");
	queue* q = (queue*)malloc(sizeof(queue));
	push(q,root);
	push(q,NULL);
	while(!isEmpty(q))
	{
		tree* x=top(q);
		printf("%d ",x->data);
		pop(q);
		
		if(x==NULL)
		{
			if(isEmpty(q))
			{
				break;
			}
			printf("\n");
			push(q,NULL);
			continue;
		}
		if(x->left)
		{	
		 push(q,x->left);
		}
		if(x->right)
		{
		 push(q,x->right);
	    }
	}
}

int main()
{
	tree* root = NULL;
	printf("enter nummber of elements in the tree followed by their values");	
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int num;
		scanf("%d",&num);
		root = BST(root,num);
	}
	level_order(root);
}
