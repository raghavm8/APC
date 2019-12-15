/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */
 int min(int a,int b)
 {
     return (a>b)?b:a;
 }
int minDepth(treenode* n) {
 if(n==NULL)
 return 0;
 if(n->left==NULL&&n->right==NULL)
 return 1;
 if(!n->left)
 return 1+minDepth(n->right);
 if(n->right==NULL)
 return 1+minDepth(n->left);
 return min(minDepth(n->left),minDepth(n->right))+1;
}

