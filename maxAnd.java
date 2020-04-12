import java.util.*;
class Main
{
    public static void main(String[] ads)
    {
        Scanner s = new Scanner(System.in);
        int l = s.nextInt();
        int r = s.nextInt();
        int ans=0;
        if(l==r)
        ans = r;
        else if(r-l == 1)
        ans = l&r;
        else if((r&(r-1))>((r-1)&(r-2)))
        ans = r&(r-1);
        else 
        ans = (r-1)&(r-2);
        
        System.out.println(ans);
    }
}