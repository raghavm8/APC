#include<stdio.h>
int max(int a,int b)
{
	return (a<b)?b:a;
}
int min(int a,int b)
{
	return (a>b)?b:a;
}
int water(int *a,int n)
{
	int left[n],right[n];
	int r=0,i;

	left[0]=a[0];
	 for(i=1;i<n;i++)
	 	left[i] = max(left[i-1],a[i]);

	 right[n-1] = a[n-1];
	  for(i=n-2;i>=0;i--)
		right[i] = max(right[i+1],a[i]);
		for(i=0;i<n;i++)
		r += (min(left[i],right[i])-a[i]);
		return r;
}
int main()
{
	int i,n=12;
	int a[n] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int x = water(a,n);
	printf("water stored = %d",x);
	return 0;
}
