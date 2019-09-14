#include<iostream>
using namespace std;
int main()
{
	int i,n;
	cout<<"enter size\n";
	cin>>n;
	int a[n];
	cout<<"enter array\n";
	for(i=0;i<n;i++)
        cin>>a[i];
	int sum=0;
	int max=a[0],temp=0;
	//sum = sum +a[0];
	// max = sum;
	for(i=0;i<n;i++)
	{
 	temp = sum + a[i];
		if(temp<a[i])
		sum = a[i];
		 else
		 sum = temp;

		if(sum>max)
		  	max = sum;


	//	begin = i;
	}
	for(i=begin;i<end;i++)
		cout<<a[i]<<" ";
		cout<<"\nsum="<<sum;
		cout<<"\nmax="<<max;
}
