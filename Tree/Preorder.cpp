#include<stdio.h>
#include<malloc.h>
// tree structure
struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};
// stack structure
struct stack
{
	 struct tree* node;
	 struct stack* next;
};
void push(stack** st,struct tree* n)
{
	struct stack* new1 = (struct stack*)malloc(sizeof(struct stack));
	new1->node=n;
	if(*st==NULL)
	{
		*st = new1;
		new1->next = NULL;
	}
	else
	{
		new1->next = *st;
		*st = new1;
	}
}
void pop(stack** st)
{
	*st = (*st)->next;
}
struct tree* top(stack* st)
{
	return st->node;
}
//funciton for inputing the values in tree
struct tree* insert(struct tree* root,int d)
{
	if(!root)
	{
		struct tree* n = (struct tree*)malloc(sizeof(struct tree*));
		n->data = d;
		n->left=NULL;
		n->right=NULL;

  return n;
	}
	else if(d < root->data)
		root->left = insert(root->left,d);
	else if(d > root->data)
		root->right = insert(root->right,d);

	return root;
}
// function for preorder traversal
 void preorder(struct tree* root)
 {
	  stack* st = (stack*)malloc(sizeof(stack));
	  st=NULL;
	 struct tree* curr = root;
   while(curr||st)
   {
   		while(curr)
	  	{
	  		printf("%d ",curr->data);
	  		push(&st,curr);
			curr = curr->left;
	    }
   		curr = top(st)->right;
  		pop(&st);
   }

 }
int main()
{

 int i,n,a;
   struct tree* root = NULL;
  printf("enter the number of elemnts to be inserted\n");
   scanf("%d",&n);
   printf("enter elements in the tree\n");
	for(i=0;i<n;i++)
 	{
     	scanf("%d",&a);
	    root = insert(root,a);
	}
	preorder(root);
	return 0;
}
