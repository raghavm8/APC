#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};
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
void preorder(struct tree* root)
{
    if (root == NULL)
	return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main()
{
 int n,a;
    struct tree* root = NULL;
	struct tree* x = NULL;
   int i;
   scanf("%d",&n);
	for(i=0;i<n;i++)
 	{
     	scanf("%d",&a);
	    root = insert(root,a);
	}
	preorder(root);
}
