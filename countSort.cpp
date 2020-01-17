#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	char a[7] = {'a','e','c','a','f','e','d'};
	int i,n=7;
	
	char temp[7];
	int count[256];
	
	for(i=0;i<256;i++)
	count[i] = 0;
	
	for(i=0;i<n;i++)
  	  count[a[i] + 1]++;
		
	for(i=1;i<256;i++)
	  count[i] += count[i-1];

	/*for(i=0;i<256;i++)
	  cout<<count[i];*/
	  
	for(i=0;i<n;i++)
	  {   
	 // cout<<a[i];
	  temp[count[a[i]]] = a[i];
	  count[a[i]]++;
	  }
	/*for(i=0;i<n;i++)
	  cout<<a[i];*/	
	for(i=0;i<n;i++)
	  a[i] = temp[i];
	  
	  for(i=0;i<n;i++)
	  cout<<a[i];
	
}
