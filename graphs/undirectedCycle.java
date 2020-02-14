import java.util.*;
 class Main{
     int v;
     LinkedList<Integer> al[];
     Main(int b)
     {
         v = b;
         al = new LinkedList[v];
         int i;
         for(i=0;i<v;i++)
            al[i] = new LinkedList();
     }
     void addEdge(int u,int v)
     {
         al[u].add(v);
         al[v].add(u);
     }
     boolean checkCycle(int v,boolean[] visited,int parent)
     {
         visited[v] = true; 
        int i; 
  
        Iterator<Integer> it = al[v].iterator(); 
        while (it.hasNext()) 
        { 
            i = it.next(); 
            if (!visited[i]) 
            { 
                if (checkCycle(i, visited, v)) 
                    return true; 
            } 
            else if (i != parent) 
                return true; 
        } 
        return false;
     }
     boolean isCyclic()
     {
         boolean b[] = new boolean[v];
         for(int i=0;i<v;i++)
            b[i] = false;
            
         for(int i=0;i<v;i++)
         {
             if(!b[i])
             if(checkCycle(i,b,-1))
                return true;
         }
         return false;
     }
     public static void main(String[] args){
         Main g1 = new Main(5); 
        g1.addEdge(1, 0); 
        g1.addEdge(0, 2); 
        g1.addEdge(2, 1); 
        g1.addEdge(0, 3); 
        g1.addEdge(3, 4); 
        if (g1.isCyclic()) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't contains cycle"); 
  
        Main g2 = new Main(3); 
        g2.addEdge(0, 1); 
        g2.addEdge(1, 2); 
        if (g2.isCyclic()) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't contains cycle");
     }
 }