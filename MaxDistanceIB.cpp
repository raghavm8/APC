
 int max(int a,int b)
 {
     return (a>b)?a:b;
}
int min(int a,int b)
 {
     return (a<b)?a:b;
}
int maximumGap(const int* a, int n) {
    
    int i,j;
    //int r[n],l[n];
    int *l = (int *)malloc(sizeof(int)*n); 
    int *r = (int *)malloc(sizeof(int)*n); 

    if (n ==1)
    return 0;
    
    l[0] = a[0];
    for(i=1;i<n;i++)
    l[i] = min(a[i],l[i-1]);
    r[n-1] = a[n-1];
    for(j=n-2;j>=0;j--)
    r[j] = max(a[j],r[j+1]);
    int k=0;
    i=0;
    j=0;
    int max = -1;
    while(i<n&&j<n)
    {
        if(l[i]<=r[j])
        {
            k = j-i;
            if(max<k)
            max = k;
            j++;
        }
        else
        i++;
    }
    return max;
}

