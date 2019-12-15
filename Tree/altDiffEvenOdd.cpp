#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// binary tree node
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// return new node
Node *createNode (int data)
{
  Node *x = malloc(sizeof(Node));
  x->data = data;
  x->left = x->right = NULL;
}

// insert into tree
Node *insert (Node *x, int data)
{
  if (x == NULL)
    return createNode(data);
  
  if (data < x->data)
    x->left = insert(x->left, data);
  else if (data > x->data)
    x->right = insert(x->right, data);
  
  return x;
}

// Queue implementation
typedef struct
{
  Node *arr[100];
  int head, tail;
} Queue;

Queue queue = {.head = 0, .tail = 0};

// push to queue
void push(Node *x)
{
  queue.arr[queue.tail++] = x;
}

// pop
void pop(void)
{
  queue.head++;
}

// empty queue
bool is_empty(void)
{
  return queue.tail - queue.head == 0;
}

// peek
Node *peek(void)
{
  return queue.arr[queue.head];
}

// size of queue
int size(void)
{
  return queue.tail - queue.head;
}

// return diff of sum
int diff_sum (Node *root)
{
  
  int diff=0;
  int a[2] = {0,0};
  push(root);
  push(NULL);
  while(!is_empty())
  {
    Node* node = peek();
    pop();
    if(node)
    {
      a[diff]=a[diff]+node->data;
      if(node->left)
        push(node->left);
      if(node->right)
        push(node->right);
    }
    else
    {
      push(NULL);
      if(diff)
        diff=0;
        else
          diff=1;
    }
  }
  return a[0]-a[1];
}

// Main function
int main(void) 
{
  int nodes;
  scanf("%d", &nodes);
  
  Node *root = NULL;
  for (int i = 0; i < nodes; i++)
  {
    int n;
    scanf("%d", &n);
    root = insert(root, n);
  }
  
  printf("%d\n", diff_sum(root));
}




