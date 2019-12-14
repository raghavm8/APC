#include<stdio.h>
int main()
{
	int i,j,n=14;
	printf("enter number of elements");
	scanf("%d",&n);
	int a[n]={1,1,1,2,2,3,3,4,5,5,6,6,6,6};
	printf("\nenter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
		 j=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		 j++;
	}
	printf("%d",j);
	return 0;
}
