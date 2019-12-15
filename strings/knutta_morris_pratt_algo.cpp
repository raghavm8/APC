#include<stdio.h>
#include<string.h>
int raghav(const char* a, const char* b) {
    int n = strlen(a); // length of main string
    int m = strlen(b);  // length of small string
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
	char s1[] = "bbbbbbbbaba";
	char s2[] = "baba";
	int x = raghav(s1,s2);
	printf("%d",x);
	return 0;
}
