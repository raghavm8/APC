#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
class point
{
	public:
	int x,y;
};
float min(float a,float b)
{
	return a>b?b:a;
}
float distance(point a,point b)
{
	float m = a.x-b.x;
	float n = a.y-b.y;
	float r = sqrt(m*m + n*n);
	return r;
}
int cmpx(const void* a,const void* b)
{
	point *A = (point*)a;
	point *B = (point*)b;
	return A->x-B->x;
}
int cmpy(const void* a,const void* b)
{
	point *A = (point*)a;
	point *B = (point*)b;
	return A->y-B->y;
}
float bruteForce(point p[],int n)
{
	int i,j;
	float ans=99999.999999;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			float res = distance(p[i],p[j]);
			if(res<ans)
			ans = res;
		}
	}
	return ans;
}
float closestInStrip(point s[],int n,float d)
{
	qsort(s,n,sizeof(point),cmpy);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n&&abs(s[j].y-s[i].y)<d;j++)
		{
			float dis = distance(s[i],s[j]);
			if(dis<d)
			d = dis;
		}
	}
	return d;
}
float closestUtil(point p[],int n)
{
	if(n<=3)
	return bruteForce(p,n);
	
	int mid = n/2;
	point midpoint  = p[mid];
	
	float dl = closestUtil(p,mid);
	float dr = closestUtil(p+mid,n-mid);
	float d = min(dl,dr);
	
	point strip[n];
	int i,size=0;
	for(i=0;i<n;i++)
	{
		if(abs(p[i].x-midpoint.x)<d)
		{
			strip[size] = p[i];
			size++;
		}
	}	
	float ans = closestInStrip(strip,size,d);
	
	return min(ans,d);
}
float closest(point p[],int n)
{
	qsort(p,n,sizeof(p),cmpx);
	
	float a = closestUtil(p,n);
	return a;
}
int main()
{
	point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
	int n = sizeof(P) / sizeof(P[0]); 
	cout << "The smallest distance is " << closest(P, n); 
	return 0; 
}
