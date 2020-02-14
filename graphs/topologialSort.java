import java.util.*;
public class Main{
    int v;
    LinkedList<Integer> al[];
    
    Main(int b)
    {
        v=b;
        al = new LinkedList[v];
        for(int i=0;i<v;i++)
        {
            al[i] = new LinkedList<Integer>();
        }
    }
    void addEdge(int u,int v)
    {
        al[u].add(v);
    }
    void topologicalSort(int v,boolean[] b,Stack s)
    {
        b[v] = true;
         Integer i;
         Iterator<Integer> it = al[v].iterator();
         while(it.hasNext())
         {
            i=it.next();
            if(!b[i])
            topologicalSort(i,b,s);
         }
         s.push(new Integer(v));
    }
    void topSort()
    {
        boolean b[] = new boolean[v];
        for(int i=0;i<v;i++)
        b[i] = false;
        
        Stack s = new Stack();
        
        for(int i=0;i<v;i++)
        if(!b[i])
        topologicalSort(i,b,s);
        
        while(!s.empty())
        {
            System.out.println(s.peek());
            s.pop();
        }
    }
    public static void main(String[] args)
    {
        Main g = new Main(6);
        g.addEdge(5, 2); 
        g.addEdge(5, 0); 
        g.addEdge(4, 0); 
        g.addEdge(4, 1); 
        g.addEdge(2, 3); 
        g.addEdge(3, 1); 
        
        g.topSort();
    }
}