import java.util.*;
public class Main
{
    public static class Graph
    {
        int v;
        LinkedList<Integer> al[];
        Graph(int v)
        {
            this.v = v;
            int i;
    
            al = new LinkedList[v];
    
            for(i=0;i<v;i++)
                al[i] = new LinkedList<Integer>();
        }
    }
    
   static void addEdge(Graph g,int src,int dest)
    {
        g.al[src].add(dest);
        g.al[dest].add(src);
    }
    
    static public void print(Graph g)
    {
        int i;
        for(i=0;i<g.v;i++)
        {
            for(Integer it : g.al[i])
            {
                System.out.print("->"+it);
            }
            System.out.println();
        }
    }
    
	public static void main(String[] args) {
		  int v = 5; 
        Graph graph = new Graph(v); 
        addEdge(graph, 0, 1); 
        addEdge(graph, 0, 4); 
        addEdge(graph, 1, 2); 
        addEdge(graph, 1, 3); 
        addEdge(graph, 1, 4); 
        addEdge(graph, 2, 3); 
        addEdge(graph, 3, 4); 
       
        // print the adjacency list representation of  
        // the above graph 
        print(graph); 
	}
}
