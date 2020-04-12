import java.util.*;
class Main
{
    int e,v;
    edge[] ed;
    Main(int a,int b)
    {
        v=a;
        e=b;
        ed = new edge[e];
    }
    static class subset
    {
        int parent;
        int rank;
        subset(int a,int b)
        {
            parent = a;
            rank = b;
        }
    }
    static class edge
    {
        int src;
        int dest;
        int weight;
        edge(){}
        edge(int a,int b,int c)
        {
            src = a;
            dest = b;
            weight = c;
        }
    }
    static int find(int i,subset[] s)
    {
        if(s[i].parent != i)
        s[i].parent = find(s[i].parent,s);
        return s[i].parent;
    }
    static void union(int x,int y,subset[] s)
    {
        int xr = find(x,s);
        int yr = find(y,s);
        if(s[xr].rank>s[yr].rank)
          s[yr].parent = xr;
        else if(s[xr].rank<s[yr].rank)
          s[xr].parent = yr;
        else
        {
            s[yr].parent = xr;
            s[xr].rank++;
        }
    }
    static edge[] mst(Main g)
    {
        edge[] res = new edge[g.v-1];
        for(int i=0;i<g.v-1;i++)
        res[i] = new edge();
        
        subset[] s = new subset[g.v];
        for(int i=0;i<g.v;i++)
        s[i] = new subset(i,0);
        
        Arrays.sort(g.ed,new Comparator<edge>(){
            public int compare(edge a,edge b)
            {
                if(a.weight>b.weight)
                return 1;
                else if(a.weight<b.weight)
                return -1;
                else return 0;
            }
        });
        int i=0;
        int re=0;
        while(re<g.v-1)
        {
           edge e = g.ed[i];
           i++;
           
           int x = find(e.src,s);
           int y = find(e.dest,s);
           
           if(x!=y)
           {
               res[re]=e;
               re++;
               union(x,y,s);
           }
        }
        return res;
    }
    public static void main(String[] adi)
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of vertices and edges in the graph");
        int v = s.nextInt();
        int e = s.nextInt();
        Main graph = new Main(v,e);
        System.out.println("Enter source, destination and weight of each edge");
        for(int i=0;i<e;i++)
        {
            int a = s.nextInt();
            int b = s.nextInt();
            int c = s.nextInt();
            graph.ed[i] = new edge(a,b,c);
        }
        edge[] res = mst(graph);
        System.out.println(res.length);
        for(edge i : res)
        {
            System.out.println(i.src+" -- " + i.dest+" == " + i.weight);
        }
        
    }
}