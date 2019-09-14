#include<stdio.h>
#include<string.h>
int raghav(const char* a, const char* b) {
    int n = strlen(a);
    int m = strlen(b);
    int i,j,index=0;
    int lsp[m];
    lsp[0]=0;
	 for(j=1;j<=m;)
	{
		if(b[i] == b[j])
		{
			lsp[j] = i+1;
			i++;
			j++;
		}
		else
		{
			if(i==0)
			{
				lsp[j] = 0;
		        j++;
			}
			else
			i = lsp[i-1];
		}
	}
    i=0;
    j=0;
    for(i=0;i<=n;)
    {
      if(a[i] == b[j])
      {
           j++;
           i++;
           if(j==m)
           {
               index = i-m;
               break;
           }
           else
           index = -1;
      }
      else
      {
          if(j==0)
          i++;
          else
          j = lsp[j-1];
      }
    }
   return index;
}

int main()
{
	char s1[] = "bbbbbbbbab";
	char s2[] = "baba";
	int x = raghav(s1,s2);
	printf("%d",x);
/*	int n = strlen(s1);
	int m = strlen(s2);
	int i=0,j=0,lsp[m];
	//printf("%d %d \n",n,m);
	lsp[0] = 0;
    for(j=1;j<=m;)
	{
		if(s2[i] == s2[j])
		{
			lsp[j] = i+1;
			i++;
			j++;
		}
		else
		{
			if(i==0)
			{
				lsp[j] = 0;
		        j++;
			}
			else
			i = lsp[i-1];
		}
	}
	  i=0;
	  j=0;
	  int index=0;
	for(i=0;i<n;)
	{
		if(s1[i] == s2[j])
		{
			i++;
			j++;
			if(j==m)
			{
				index = i;
				printf("index is %d\n",index-m);
				j=0;
				break;
			}
			 //index=0;
		}
		else
		{
			if(j==0)
			{
			   i++;
			}
			else
			{
				j = lsp[j-1];
			}
		}
	}
	printf("%d",index-m);*/
}
