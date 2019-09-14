#include<iostream>
#include<stdlib.h>
int comparator(const void *a,const void *b)
{
    return *((int*)a)-*((int*)b);
}
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter size of an array: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
   qsort(a,n,sizeof(int),comparator);
   if(n%2!=0)
  m=n-1;
  else
    m=n;
    for(int i=0;i<m;i=i+2)
    {
        int t=a[i];a[i]=a[i+1];a[i+1]=t;
    }
    cout<<"Array after conversion to wave form: "<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
