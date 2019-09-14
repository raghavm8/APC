#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,i,j,k,l,m,n,x,size;
	cout<<"enter size\n";
	cin>>size;
	m = size;
	n = size;
	int arr[m][n];
/*	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		  arr[i][j] = 0;
		}
	} */
	a = 0;   //first row
	b = 0;    // first col
	c = m;   //last row
	d = n;   //last column
	x=1;


	while(a<c && b<d)
	{
		for(i=b;i<d;i++)
			arr[a][i] = x++;
		a++;
		for(j=a;j<c;j++)
			arr[j][d-1] = x++;
		d--;
		for(k=d-1;k>=b;k--)
			arr[c-1][k] = x++;
		c--;
		for(l=c-1;l>=a;l--)
			arr[l][b] = x++;
		b++;

 }
// cout<<"gvu";
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
