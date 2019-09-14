#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter size";
	cin>>n;
	cout<<"enter array";
	int a[n],i,j=0;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(i<n+2 && a[i] == a[i+1] && a[i+1] == a[i+2])
		continue;
		else
		{
		a[j] = a[i];
		j++;
		}
	}
	//a[j++] = a[n-2];
	//	a[j++] = a[n-1];
		for(i=0;i<j;i++)
		cout<<a[i];
}
