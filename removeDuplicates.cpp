#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter array size";
	cin>>n;
	int a[n];
	cout<<"enter array in sorted order";
	int i,j=0;
	for(i=0;i<n;i++)
	cin>>a[i];
		for(i=0;i<n;i++)
		{
			if(a[j]!=a[i])
			{
				j++;
				a[j] = a[i];
			}
		}
		a[j++] = a[n-1]
		;
			  for(i=0;i<j;i++)
			  cout<<a[i];
}
