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
int top(stack* st)
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
int area(int a[],int n)
{
	stack* st;
	st = create(100);
	int max=0,area=0,x,i,d=0;
	for(i=0;i<n;i++)
	{
	   if(isEmpty(st) || a[i]>=a[top(st)])
	   push(st,i);
	   else
	   {
		   while(!isEmpty(st) && a[i]<a[top(st)])
		   {
			   x = a[top(st)];
			int y = pop(st);
			    d = isEmpty(st)?i:(i-top(st)-1);
			   int area = d*x;
			   if(max<area)
				max = area;
		   }
		   push(st,i);
	   }
	}
	return max;
}
int main()
{
	int ar,i,n=8;
	//scanf("%d",&n);
	stack* st;
	st = create(100);
	int a[n] = {5,2,4,5,4,3,6,1};
	//for(i=0;i<n;i++)
	//scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	 ar = area(a,n);
	 printf("\nmax area = %d\n",ar);
	 return 0;
}
