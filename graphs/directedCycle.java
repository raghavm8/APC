import java.util.*;

public class Main{
    int v;
    LinkedList<Integer> al[];
    
    Main(int b)
    {
        v = b;
        al = new LinkedList[v];
        for(int i=0;i<v;i++)
        al[i] = new LinkedList();
    }
    void addEdge(int u,int v)
    {
        al[u].add(v);
    }
    boolean checkCycle(int i,boolean[] vis,boolean[] res)
    {
        if(res[i])
        return true;
        if(vis[i])
        return false;
        
        res[i] = true;
        vis[i] = true;
        
        for(Integer c : al[i])
        {
            if(checkCycle(c,vis,res));
            return true;
        }
        res[i] = false;
        return false;
    }
    boolean isCyclic()
    {
        boolean vis[] = new boolean[v];
        boolean res[] = new boolean[v];
        
        for(int i=0;i<v;i++)
            if(checkCycle(i,vis,res))
                return true;
        return false;
    }
    void print()
    {
        int i;
        for(i=0;i<v;i++)
        {
            for(Integer c : al[i])
            {
                System.out.print(c + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args)
    {
        Main graph = new Main(4);
        graph.addEdge(0, 1); 
        graph.addEdge(0, 2); 
        graph.addEdge(1, 2); 
        graph.addEdge(2, 0); 
        graph.addEdge(2, 3); 
        graph.addEdge(3, 3);
        
        if(graph.isCyclic())
        System.out.println("cycle present");
        else
        System.out.println("not present");
         graph.print();
    }
}