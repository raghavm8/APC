#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;

  }TreeNode;

int search(int *a,int start,int end,int element)
{
	int i;
	for(i=start;i<=end,i++)
	if(a[i] == element)
	break;
	return i;
}

void postOrder(TreeNode* r)
{

    if( r== NULL)
        return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%d ", r->val);
}

  TreeNode* initialize(int val)
  {
      TreeNode* nn = (TreeNode*)malloc(sizeof(TreeNode));
      nn->val = val;
      nn->left = NULL;
      nn->right = NULL;
      return nn;
  }


TreeNode* createTree(int *a,int *b,int start,int end,int* index)
{
  if(start>end)
    return NULL;
  
  TreeNode* root = initialize(*index);
  *index--;
  
  if(start==end)
  return root;
  
  int i = search(a,start,end,root->val);
  
  root->right = createTree(a,b,i+1,end,index);
  root->left = createTree(a,b,start,i-1,index);
  return root;
  
}
 
TreeNode* buildTree(int* a, int* b, int s) {
	int index=0;
  createTree(b,a,0,size-1,&index);
}

int main()
{

    int n, i;

    scanf("%d", &n);
    int A[n], B[n];
    for(i=0;i<n;i++)
    {
        scanf("%d", &A[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d", &B[i]);
    }
    TreeNode* Res = buildTree(A,B,n);

    postOrder(Res);
}
