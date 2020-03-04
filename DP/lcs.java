import java.util.*;
import java.lang.*;
public class Main{
    static char[] lcs(String x,String y)
    {
       // System.out.println("in lcs function");
        int n=x.length();
        int m=y.length();
        int l[][] = new int[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                l[i][j]=0;
                else if(x.charAt(i-1)==y.charAt(j-1))
                l[i][j] = l[i-1][j-1]+1;
                else
                l[i][j] = Math.max(l[i-1][j],l[i][j-1]);
            }
        }
        int lt = l[n][m];
        //System.out.println(lt);
        int index = lt;
        char c[] = new char[index+1];
        int i=n,j=m;
      //  System.out.println(c.length);
        while(i>0&&j>0)
        {
            if(x.charAt(i-1)==y.charAt(j-1))
            {
                c[index-1] = x.charAt(i-1);
                i--;
                j--;
                index--;
            }
            else if(l[i-1][j]>l[i][j-1])
            i--;
            else 
            j--;
        }
        System.out.println("end of lcs");
        return c;
    }
    public static void main(String[] af)
    {
        String X = "AGGTAB"; 
        String Y = "GXTXAYB"; 
        char c[] = lcs(X, Y);
        System.out.println(c.length);
        for(int i=0;i<c.length;i++)
        System.out.print(c[i]);
    }
}