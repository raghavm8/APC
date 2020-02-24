import java.util.*;
class Main{
    static int count(int s,int n)
    {
        int i,j;
        int ans[] = new int[s];
        ans[0]=1;
        ans[1]=1;
        for(i=2;i<s;i++)
        {
            ans[i]=0;
            for(j=1;j<=i&&j<=n;j++)
            {
                ans[i] += ans[i-j];   
            }
        }
        return ans[s-1];
    }
    static int ways(int s,int n)
    {
        return count(s+1,n);
    }
    public static void main(String[] sdc)
    {
         int s = 4, m = 2; 
        System.out.println("Nuber of ways = " + ways(s, m)); 
    }
}