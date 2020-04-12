import java.util.*;
 class Main{
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
        void bfs(int f)
        {
            boolean b[] = new boolean[v];
            LinkedList<Integer> q = new LinkedList<Integer>();            
            b[f] = true;
            q.add(f);
            while(q.size()!=0)
            {
                int s = q.poll();
                System.out.print(s + " ");
                Iterator<Integer> it = al[s].listIterator();
                while(it.hasNext())
                {
                    int n = it.next();
                    if(b[n] != true)
                    {
                        b[n] = true;
                        q.add(n);
                    }
                }
            }
        }
     public static void main(String[] args)
     {
         Main g = new Main(4);
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(1, 2); 
        g.addEdge(2, 0); 
        g.addEdge(2, 3); 
        g.addEdge(3, 3);
        
        g.bfs(2);
     }
 }