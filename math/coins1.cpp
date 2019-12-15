#include<stdio.h>
int coins(int *arr,int n,int *val,int m)
{
	int a[m][n];
	for(i=0;i<n;i++)
	a[0][i]=0;

	/*for(i=1;i<n;i++)
	   for(j=1;j<n;j++)
		  a[i][j]=1;*/

	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if()
		}
	}
}
int main()
{
	int i,j,n,m;
	printf("enter total amount\n");
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<n+1;i++)
	{
	  a[i]=i;
	}
	printf("enter number of coins available\n");
	scanf("%d",&m);
	int val[m+1];
	printf("enter value of all coins in increasing order\n");
	val[0]=0;
	for(i=1;i<m+1;i++)
	scanf("%d",&val[i]);
	j = coins(a,n+1,val,m+1);
	printf("%d",j);
	return 0;
}
