#include<stdio.h>
int power(int n,int m)
{
	int x;
	if(m==1)
	return m;
	 x = power(n,m/2);
	if(n%2==0)
	return x*x;
	else
	return n*x*x;
}
int main()
{
	int n,m;
	printf("Enter Number\n");
	scanf("%d",&n);
	printf("Enter Power\n");
	scanf("%d",&m);
	int x=power(n,m);
	printf("ans = %d",x);
	return 0;
}
