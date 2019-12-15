#include<stdio.h>
int max(int a,int b)
{
	return (a>b)?a:b;
}
int min(int a,int b)
{
	return (a<b)?a:b;
}
int hcf(int a,int b)
{
	int y,x = min(a,b);
	if(x==0)
	return max(a,b);
	else
	{
		if(a>b)
		return hcf(a%b,b);
		else
		return hcf(b%a,a);
	}
}
int main()
{
   int a,b;
   printf("enter first number\n");
   scanf("%d",&a);
   printf("enter second number\n");
   scanf("%d",&b);
   int x = hcf(a,b);
   printf("hcf=%d",x);
   return 0;
}
