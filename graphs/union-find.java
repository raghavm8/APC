import java.util.*;
import java.lang.*;
class Main
{
    static class edge
    {
        int src,dest;
        edge(){}
        edge(int a,int b)
        {
            src = a;
            dest = b;
        }
    }
    int v,e;
    edge ed[];
    Main(int a,int b)
    {
        v = a;
        e = b;
        ed = new edge[e];
    }
    static int find(int i,int[] parent)
    {
        if(parent[i] == -1)
        return i;
        return find(parent[i],parent);
    }
    static void union(int x,int y,int[] parent)
    {
        int xs = find(x,parent);
        int ys = find(y,parent);
        parent[ys] = xs;
    }
    boolean isCycle(Main g)
    {
        int parent[] = new int[g.v];
        for(int i=0;i<v;i++)
        parent[i] = -1;
        
        for(int i=0;i<g.e;i++)
        {
            int x = find(g.ed[i].src,parent);
            int y = find(g.ed[i].dest,parent);
            
            if(x==y)
            return true; 
            
            union(x,y,parent);
        }
        return false;
    }
    public static void main(String[] ad)
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