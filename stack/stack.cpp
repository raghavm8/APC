#include<stdio.h>
#include<malloc.h>
typedef struct stack
{
	unsigned capacity;
	int* array;
	int top;
};
int isEmpty(stack* st)
{
	if(st->top == -1)
	return true;
	else
	return false;
}
int isFull(stack* st)
{
	if(st->top == st->capacity-1)
	return true;
	return false;
}
void push(stack* st,int x)
{
	if(isFull(st))
	{
		printf("stack is full\n");
		return;
	}
	else
	st->array[++st->top] = x;
}
int pop(stack* st)
{
	int x;
	if(isEmpty(st))
	{
   		printf("stack empty\n");
   		return -1;
   }
   else
   {
	  x = st->array[st->top--];
   }
   return x;
}
int peek(stack* st)
{
   if(isEmpty(st))
   {
   		printf("stack empty\n");
   		return -1;
   }
   else
   return st->array[st->top];
}
stack* create(unsigned cap)
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->top=-1;
	s->capacity = cap;
	s->array = (int*)malloc(s->capacity*sizeof(int));
	return s;
}
void print(stack* st)
{
	int i;
	for(i=st->top;i>=0;i--)
	printf("%d\n",st->array[i]);
}
int main()
{
	stack* st;
	st = create(100);
	if(isEmpty(st))
	printf("stack empty\n");
	else
	printf("not empty\n");
	push(st,10);
	push(st,20);
	push(st,30);
	push(st,40);
	int x = pop(st);
	int y = peek(st);
	printf("%d %d\n",x,y);
	print(st);
}
