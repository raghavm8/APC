#include <iostream>
using namespace std;

int main() {
        int n,t,j;
        cin>>t;
        for(j=0;j<t;j++)
        {
            cin>>n;
            int k=0,i,a[n],b[n];
            for(i=0;i<n;i++)
             cin>>a[i];

            b[n-1]=1;
            for(i=n-2;i>=0;i--)
            {
                if((a[i]>0&&a[i+1]<0)||(a[i]<0&&a[i+1]>0))
                {
                    b[i]=b[i+1]+1;
                }
                else
                {
                    b[i]=1;
                }
            }
            //b[n-1]=1;
            for(i=0;i<n;i++)
            cout<<b[i]<<" ";
            cout<<"\n";
        }
	return 0;
}

