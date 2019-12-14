#include<stdio.h>
int main()
{
	int j=0,i,n,m;
	printf("enter number of element\n");
	scanf("%d",&n);
	int a[n];

	printf("enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter number of maximum's required\n");
	scanf("%d",&m);
	int sum=0,max=a[0];
	int count=0;
	while(j!=m)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]>=max)
			{
		   	    max=a[i];
				count=i;
			}
	   }
	   j++;
	    sum+=max;
		a[count]=0;
		max=a[0];
	}
   	printf("sum of top 5 max elements is=");
	printf("\n%d",sum);
	return 0;
}
