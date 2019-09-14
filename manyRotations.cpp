#include<iostream>
using namespace std;
int main()
{
	int i,k,j,n;
	cout<<"enter size";
	cin>>n;
	int a[n];
	cout<<"enter array";
	for(i=0;i<n;i++)
	cin>>a[i];
		 k = 997%n;
		 int t;

		 for(i=0;i<k;i++)
		 {
		 	t = a[0];

			for(j=0;j<n;j++)
			{
				a[j] = a[j+1];
			}
			a[n-1]=t;
		 }
		 for(i=0;i<n;i++)
			cout<<a[i]<<" ";
}
