#include<stdio.h>
void print(int (*ar)[5], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
	printf("%d\n",*(*ar+i)) ;
   }
}
int main ()
{
	int a[5] = {1,2,3,4,5};
	print(&a,5);
}
