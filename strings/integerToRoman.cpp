#include<iostream>
#include<string.h>
using namespace std;
// prototype of logic
string Solution::intToRoman(int n) {

    int no[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string ro[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int i=0,k=0;
    string res = "";
    while(n!=0)
    {
        while(n >= no[i])
        {
            res += ro[i];
            n-=no[i];
        }
        i++;
    }
    return res;
}
int main()
{
	return 0;
}
