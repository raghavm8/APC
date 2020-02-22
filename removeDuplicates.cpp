#include<iostream>
#include<stdlib.h>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *((int*)a) - *((int*)b);
}
int main()
{
	int n;
	cout<<"enter array size";
	cin>>n;
	int a[n];
	cout<<"enter array in sorted order\n";
	int i,j=0;
	for(i=0;i<n;i++)
	cin>>a[i];
	qsort(a,n,sizeof(int),cmp);
		for(i=0;i<n;i++)
		{
			if(a[j]!=a[i])
			{
				j++;
				a[j] = a[i];
			}
		}
		a[j++] = a[n-1];
	
			  for(i=0;i<j;i++)
			  cout<<a[i]<<" ";
	return 0;
}
