#include<stdio.h>
void sort(int a[],int n)
{
	int j,curr,i;
	 for(i=1;i<n;i++)
	 {
	 	curr = a[i];
	 	j = i-1;
	 	while(j>=0 && a[j]>curr)
			{
				a[j+1] = a[j];
				j--;
		 	}
		 	a[j+1] = curr;
	 }
	
}
int main()
{
	int n;
	int i;
	printf("enter arrray size\n");
 scanf("%d",&n);
	int a[n];
	printf("enter array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,n);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
			
}
