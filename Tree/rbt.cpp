// logic/concept to check the rbt is valid or not
// RBT(red black tree)
// root is always black
// new node is red
// null/leaf is black
// a red node has both black children
// root to any leaf -> no. of black nodes has to be constant

// conditions and actions to be taken(LLRBT) :-
/*
1. if right node is red and leaf is black -> left rotate
2. if left child is red and left grand child is red -> right rotate
3. both childredn can not be red->flip color
*/
#include<stdio.h>
#include<malloc.h>
struct node{
	struct node* left;
	struct node* right;
	int data;
	int val;
};
node flipcolor(node n)
{
	n.color=red;
	n.left.color = black;
	n.right.color = black;
	return n;
}
node leftRotate(node n)
{
   struct node* t;
	t=n.right;
	n.right = t.left;
	t.left = n;
	t.color=n.color;
	n.color=red;
	return t;
}
node rightRotate(node* n)
{
	struct node* t;
	t=n.left;
	n.left = t.right;
	t.right=n;
	t.color = n.color;
	n.color=red;
	return t;
}
node* insert(node* n,int key)
{
	if(n == NULL)
	return new node(key);
	if(n.data>key)
	n.left=insert(n.left,key);
	else if(n.data<key)
	n.right = insert(n.right,key);
	
	
	if(n.left.color == black && n.right.color == red)
	n=leftRotate(n);
	if(n.left.color == red && n.left.left.color == red)
	n = rightRotate(n);
	if(n.left.color == red && n.right.color == red)
	n = flipcolor(n);
}
int main()
{
	public insert(k);
	root = insert(root,k);
	root.color = black;
}
































