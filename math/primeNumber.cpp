#include<stdio.h>
int main()
{
	int n;
	printf("enter count");
	scanf("%d",&n);
	int i,j;
	int a[n+1];
	for(i=0;i<n;i++)
	{
	   a[i]=i;
	}
	int arr[n];
	for(i=2;i*i<=n;i++)
	{
		for(j=i*i;j<=n;j+=i)
		{
		   if(a[j]%i==0)
		   a[j]=-1;
		}
	}
	j=0;
	for(i=2;i<n;i++)
	{
		if(a[i]!=-1)
		arr[j++]=a[i];
	}
	for(i=0;i<j;i++)
	printf("%d ",arr[i]);
	return 0;
}
