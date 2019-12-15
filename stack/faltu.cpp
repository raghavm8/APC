#include<stdio.h>
#include<malloc.h>
struct stack
{
    unsigned capacity;
    int* array;
    int top;
};
int isEmpty(struct stack* st)
{
    if(st->top == -1)
    return 1;
    else
    return 0;
}
void push(struct stack* st,int x)
{

  //  else
    st->array[++st->top] = x;
}
void pop(struct stack* st)
{
    int x;

      x = st->array[st->top--];
   //return x;
}
int top(struct stack* st)
{
   return st->array[st->top];
}
struct stack* create(unsigned cap)
{
   struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->capacity = cap;
    s->array = (int*)malloc(s->capacity*sizeof(int));
    return s;
}

int* prevSmaller(int* a, int n) {
    //*len1 = n;
    int *g = (int*)malloc(n*sizeof(int));
    struct stack* s = create(n);
    int i;
    for(i=0;i<n;i++)
    {
        g[i]=-1;
    }
       for(i=0;i<n;i++)
       {
           if(isEmpty(s)||a[i]>top(s))
           {
              pop(s);
                push(s,i);
           }
           else
           {
               while(!isEmpty(s)&&a[i]<=top(s))
               {
               	   printf("%d\n",top(s));
                   g[i] = top(s);
                   pop(s);
               }
               push(s,g[i]);
           }
       }
	for(i=0;i<n;i++)
	printf("%d ",g[i]);
}

int main()
{
	int ar,i,n=5;
	//scanf("%d",&n);
	stack* st;
	st = create(100);
	int a[n] = {4,5,2,10,8};
	//for(i=0;i<n;i++)
	//scanf("%d",&a[i]);
	   prevSmaller(a,n);
	 return 0;
}
