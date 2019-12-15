#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct queue
{
	struct node* front;
	struct node* rear;
};
struct node* createNode(struct queue* q,int d)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->next=NULL;
	return temp;
}
struct queue* createQueue()
{
	struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
	temp->front=NULL;
	temp->rear=NULL;
	return temp; 
}
void push(struct queue* q,int d)
{
	struct node* temp = createNode(q,d);
	if(q->rear==NULL)
	{
		q->rear=temp;
		q->front=temp;
		return;
	}	
		q->rear=temp;
		q->rear->next=temp;		
}
void pop(struct queue* q)
{
	if(q->front->next)
	q->front=q->front->next;
	else
	{
		q->front=NULL;
		q->rear=NULL;
	}
}
struct node* peek(struct queue* q)
{
	return q->front;
}
void print(struct queue* q)
{
	struct queue* temp=q;
	while(q->front!=q->rear)
	{
		printf("%d",q->front->data);
		q->front=q->front->next;
	}
}
int main()
{
	struct queue* q = createQueue();
	push(q,10);
	push(q,20);
	push(q,30);
	pop(q);
	push(q,40);
	push(q,50);
	print(q);
}
