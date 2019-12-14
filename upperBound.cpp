#include<stdio.h>
int upperBound(int n,int a[10],int s,int e,int k)
{
	   int mid=0,ans=-1;
	   while(s<=e)
	   {
			mid = (s+e)/2;
			if(a[mid] <= k)
			{
				ans = k;
				s = mid + 1;
			}
			else if (a[mid] > k)
				e = mid - 1;
	   }
	   return ans;
}

int main()
{
	int i,n,start,end;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	start = 0;
	end = n-1;
	printf("enter element to be searched");
	int k;
	scanf("%d",&k);
	int x = upperBound(n,a,start,end,k);
	if(x==-1)
	printf("element not present");
	else
	printf("%d",x);
	return 0;
}
