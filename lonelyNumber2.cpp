#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j=0,k=0,t1=0,t2=0;
	//scanf("%d",&n);
	int a[6] = {1,2,3,4,3,1};
	//for(i=0;i<n;i++)
	//scanf("%d",&a[i]);
			  n=6;
	for(i=0;i<n;i++)
	{
      k = k^a[i];
      //printf("%d ",k);
	}
	j=k>>1;
	//printf("%d\n",j);
	while(j&1 != 1)
	{
		//printf("jhg");
		j=j>>1;
	}
	 for(i=0;i<n;i++)
	 {
	 	if(a[i]&j == 1)
	 	t1 = j^a[i];
	 	else
	 	t2 = j^a[i];
     }
	 
	printf("%d %d",t1,t2);
}
