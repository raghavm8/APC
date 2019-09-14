#include<iostream>
using namespace std;
void swap (int&,int&);
int main ()
{
	int a,b;
	cin >> a>> b;
	cout << "swap before oper.  "<<a<<"\n"<<b;
	swap(a,b);
	cout <<endl<< "swap after oper.  "<<a<<"\n"<<b;
	
}
void swap (int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
