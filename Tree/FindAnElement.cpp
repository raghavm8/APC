#include<stdio.h>
#include<malloc.h>
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
int find(struct tree* root,int elem)
{
	if(root==NULL)
	return 0;
	if(root->data == elem)
	return 1;
	find(root->left,elem);
	find(root->right,elem);
}
int findElements(struct tree* root,int a,int b)
{
	if(find(root,a)&&find(root,b));
	return 1;
	return 0;
}
int length(struct tree* root)
{
	if(!root)
	return 0;
	else
	return length(root->left)+length(root->right)+1;
}
int path(struct tree* root,int val,int* arr,int k)
{
	 //k is the count for array
	 //val is the number whose path is required
	 //arr will store the path
	int count=0;
	if(root==NULL)
	return 0;
	arr[count++]=root->data;
	if(root->data==val)
	return 1;
	int m = path(root->left,val,arr,k)||path(root->right,val,arr,k);
	 arr[count--];
	k=count;
}

int lca(struct tree* root,int a,int b,int n)
{
	//n is the size of the tree
	//struct tree* curr = root;
	int x[n],y[n];             //two arrays to store path of each element
	int i=0,j=0;              //two elements to take the size of path
	path(root,a,x,i);
	path(root,a,y,j);
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
	    root=insert(root,a);
	}
	int x,y;
	printf("enter elements required for least common ancestor\n");
	scanf("%d%d",&x,&y);
	int len=length(root);
//	printf("%d",len);
	if(findElements(root,x,y))
	{
	  int l=lca(root,x,y,len);
	   printf("least common ancestor = %d\n",l);
	}
	else
	printf("lca not possible\n");
	return 0;
}
