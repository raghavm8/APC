#include<iostream>
using namespace std;

int main ()
{
	int j,n,k,i,t;
	 cout<<"enter size\n";
	 cin>>n;
	cout<<"enter group size\n";
	 cin>>k;
	int a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i+=k)
	{   if((i+k)<n)
		{
		    for(j=0;j<k/2;j++)
		    {

			  t=a[i+j];
			  a[i+j]=a[i+k-j-1];
			  a[i+k-1-j]=t;
			}
	    }
		else
		{
			k=n-i;
		    for(j=0;j<k/2;j++)
		    {

			  t=a[i+j];
			  a[i+j]=a[i+k-j-1];
			  a[i+k-1-j]=t;
			}
		}

	}
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
