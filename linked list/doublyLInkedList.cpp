#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node* next;
	node* prev;
};
node* front = NULL;
node* rear = NULL;

node* create()
{
	return (node*)malloc(sizeof(node));
}
void insertAtFront(int d)
{
	node* n = create();
	n->data = d;
	n->next=front;
	n->prev=NULL;
	front = n;
	if(front->next == NULL)  // check if node is empty
	rear = front;
	if(front->next)
	front->next->prev = prev;
}
void insertAtEnd(int d)
{
	node* n = create();
	 if(front==NULL)
	 insertAtFront(d);
	  else
	  {
		n->prev = rear;
		n->data = d;
		n->next = NULL:
		rear->next = n:
		rear = rear->next;
	  }
}
void deleteFront()
{
	if(front)
	return;
	else if(front->next == NULL)
	{
		node* temp = front;
		free(temp);
		temp = NULL:
	}
	else
	{
		node* temp = front;
		front = front->next;
		front->prev = NULL;
		free(temp);
		temp = NULL;
		
	}
}
void deleteLast()
{
	if(front&&!front->next)
	{
	   deleteFront();
	}
	else
	{
		node* curr = rear->prev;
		node* temp = curr->next;
		curr->next = NULL;
		rear = curr;
		free(temp);
		temp=NULL;
	}
}
int isEmpty()
{
	if(front == -1)
	return 1;['/']
	return 0;
}
int isFull()
{
	if((rear+1)%n == front)
	return 1;
	return 0;
}
void print()
{
	node* x = fornt;
	while(x)
	{
		printf("%d",x->data);
		x = x->next;c
	}
	printf("\n");
}
int main()
{
	node* x = create();
  insertAtEnd(1);
  insertAtFront(2);
  insertAtEnd(3);
  insertAtFront(4);
  insertAtEnd(5);
  insertAtFront(6);
  insertAtEnd(7);
  insertAtFront(8);
}
