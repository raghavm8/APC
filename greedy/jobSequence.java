import java.util.*;
class Main
{
    static class job
    {
        int profit;
        int dead;
        char id;
        job(char c,int d,int p)
        {
            id = c;
            dead = d;
            profit = p;
        }
    }
    static void schedule(job[] j)
    {
        int n = j.length;
        Arrays.sort(j,new Comparator<job>(){
           public int compare(job a,job b)
           {
               if(a.profit>b.profit)
               return -1;
               else if(a.profit<b.profit)
               return 1;
               else return 0;
           }
        });
        
        /*for(int i=0;i<n;i++)
            System.out.println(j[i].profit);*/
        boolean[] b = new boolean[n];
        int[] index = new int[n];
        
        for(int i=0;i<n;i++)
            b[i] = false;
            
        for(int i=0;i<n;i++)
        {
            for(int k=Math.min(n,j[i].dead)-1;k>=0;k--)
            {
                if(b[k]==false)
                {
                  
                    b[k] = true;
                    index[k] = i;
                    break;
                }
            }
        }
        int p=0;
        String s="";
        for(int i=0;i<n;i++)
        {
            if(b[i]==true)
            {
                p +=  j[index[i]].profit;
                s += j[index[i]].id;
            }
        }
        System.out.print("profit = " + p + " seq = " + s);
    }
    public static void main(String[] ad)
    {
        int n;
        Scanner s = new Scanner(System.in);
        n=s.nextInt();
        job[] j = new job[n];
        System.out.println("enter id as Character deadline and profit " + n + " times");
        int d,p;
        char c;
        for(int i=0;i<n;i++)
        {
            c=s.next().charAt(0);
            d=s.nextInt();
            p=s.nextInt();
            j[i] = new job(c,d,p);
        }
        schedule(j);
    }
}