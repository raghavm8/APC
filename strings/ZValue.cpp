#include<iostream>
using namespace std;

void getZ(string s,int n,int z[])
{
	int l,r,i,k;
	l=0;
	r=0;
	for(i=1;i<n;i++)
	{
		if(i>r)
		{
			l=i;
			r=i;
			while(r<n && s[r-l]==s[r])
			r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			k=i-l;
			if(z[k]<r-i+1)
			z[i]=z[k];
			else
			{
				l=i;
				while(r<n&&s[r-l]==s[r])
				r++;
				z[i]=r-l;
				r--;	
			}
		}
	}
}
int main()
{
	int i;
	string str,pattern;
	cin>>str;
	cin>>pattern;
	cout<<"Original String = "<<str<<"\n";
	cout<<"pattern to be found = "<<pattern<<"\n";
	str = pattern + "$" + str;
	//cout<<str;
	int n = str.length();
	int z[n];
	for(i=0;i<n;i++)
	{
		z[i] = 0;
	}
	getZ(str,n,z);
	/*for(i=0;i<n;i++)
	{
		cout<<z[i]<<" \n";
	}*/
	for(i=1;i<n;i++)
	{
		if(z[i] == pattern.length())
		cout<<"pattern in present at index = "<<i-pattern.length()-1<<"\n";
	}
	return 0;
}
