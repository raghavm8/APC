import java.util.*;
class Main
{
    public static int or(int l,int r)
    {
        int max = 64;
        int ans=0;
        for(int i=max-1;i>=0;i--)
        {
            int p = 1<<i;
            int lb = (l>>i)&1;
            int rb = (r>>i)&1;
            
            if(rb==1&&lb==0)
            {
            ans = ans + (p<<1)-1;
            break;
            }
            if(rb == 1)
            ans += p;
        }
        return ans;
    }
    public static void main(String[] ads)
    {
        Scanner s = new Scanner(System.in);
        int l = s.nextInt();
        int r = s.nextInt();
        int ans=0;
        
        ans = or(l,r);
        System.out.println(ans);
    }
}