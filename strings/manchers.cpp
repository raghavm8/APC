#include<iostream>
#include<string.h>
using namespace std;
string longestPalindrome(string A) {
    string a="";
    a+="$";
    for(int i=0;i<A.length();i++)
    {
        a+=A[i];
        a+="$";
    }
    int r[a.length()];
    r[0]=1;	
    int left=1,right=1;
    int i;
	for( i=1;i<a.length();i++)
    {
        if(i>=right)
        {
            left=i;
            right=i;
            while(left>=0&&a[left]==a[right]&&right<a.length())
            {
                left--;
                right++;
            }
            left++;
            right--;
            r[i]=right-left+1;
        }
        else
        {
            if(i+r[left+right-i]/2<right)
            {
                r[i]=r[left+right-i];
            }
            else if(i+r[left+right-i]/2>right)
            {
                r[i]=(right-i)*2+1;
            }
            else
            {
                left=i;right=i;
                i--;
            }
        }
    }
    int max=1,index=0;
    for(int i=0;i<a.length();i++)
    {
        if(r[i]>max)
        {
            max=r[i];
            index=i;
        }
    }
    int start=index-(max/2);
    int end=index+(max/2);
    string res="";
    while(start!=end)
    {
        if(a[start]!='$')
            res+=a[start];
        start++;
    }
    return res;
    
}
int main()
{
	string b,a;
	cin>>a;//abacabacabb = example
	b = longestPalindrome(a);
	cout<<b;
	return 0;
}
