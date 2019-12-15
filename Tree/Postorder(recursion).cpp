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
void postorder(struct tree* root)
{
    if (root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
	printf("%d ",root->data);
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
	postorder(root);
}
