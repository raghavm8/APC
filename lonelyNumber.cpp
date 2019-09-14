#include<stdio.h>
#include<math.h>
int  main()
{
	//largest element of array should be less than size of array
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	 int m =0;
	 for(i=0;i<n;i++)
	 {
		m =  abs(a[i]);
		a[m] = a[m]*(-1);
	 }
	 for(i=0;i<n;i++)
	 if(a[i]<0)
	 printf("%d",a[i]*-1);
	 return 0;
}
