import java.util.*;
import java.lang.*;
public class Main
{
    int v,e;
    edge ed[];
    Main(int a,int b)
    {
        v=a;
        e=b;
        ed = new edge[e];
    }
    static class edge
    {
       int src;
       int dest;
       edge(int a,int b)
       {
           src=a;
           dest=b;
       }
    }
    static class subset
    {
        int rank;
        int parent;
        subset(int a,int b)
        {
            rank=a;
            parent=b;
        }
    }
    static int find(subset[] s,int i)
    {
        if(s[i].parent != i)
          s[i].parent = find(s,s[i].parent);
        
        return s[i].parent;
    }
    static void union(int x,int y,subset[] s)
    {
        int xr = find(s,x);
        int yr = find(s,y);
        
        if(s[xr].rank > s[yr].rank)
            s[yr].parent = xr;
        else if(s[xr].rank < s[yr].rank)
            s[xr].parent = yr;
        else
        {
            s[xr].parent = yr;
            s[yr].rank++;
        }
    }
    static boolean isCycle(Main g)
    {
        int v = g.v;
        int e = g.e;
        subset[] s = new subset[v];
        
        for(int i=0;i<v;i++)
            s[i] = new subset(0,i);
        
        for(int i=0;i<e;i++)
        {
            int x = find(s,g.ed[i].src);
            int y = find(s,g.ed[i].dest);
            
            if(x==y)
            return true;
            
            union(x,y,s);
        }
        return false;
    }
    public static void main(String[] ads)
    {
         Scanner s = new Scanner(System.in);
        System.out.println("enter the number of vertices and edges");
        int V = s.nextInt();
        int E = s.nextInt();
        Main g = new Main(V, E); 
        
        System.out.println("enter source and destination for all edges");
        for(int i=0;i<g.e;i++)
        {
            int x = s.nextInt();
            int y = s.nextInt();
            g.ed[i] = new edge(x,y);
        }
        if (g.isCycle(g)==true) 
            System.out.println( "graph contains cycle" ); 
        else
            System.out.println( "graph doesn't contain cycle" );
    }
}