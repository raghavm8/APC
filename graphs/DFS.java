import java.util.*;
 class Main{
        int v;
        LinkedList<Integer> al[];
        
        Main(int b)
        {
            v=b;
            al = new LinkedList[v];
            int i;
            for(i=0;i<v;i++)
            {
                al[i] = new LinkedList<Integer>();
            }
        }
        void addEdge(int u,int v)
        {
            al[u].add(v);
        }
        void dfs(int f)
        {
            boolean b[] = new boolean[v];
            Stack<Integer> q = new Stack<Integer>();
             
            for(int i=0;i<v;i++)
                b[i] = false;
            
             q.push(f);
            
            while(q.empty()==false)
            {
                int s = q.peek();
                q.pop();
                
                if(b[s]==false)
                {
                    System.out.print(s + " ");
                    b[s] = true;
                }
                
                Iterator<Integer> it = al[s].listIterator();
                while(it.hasNext())
                {
                    int x = it.next();
                    if(!b[x])
                    {
                        q.push(x);
                    }
                }
            }
        }
     public static void main(String[] args)
     {
         Main g = new Main(5);
         g.addEdge(1, 0); 
        g.addEdge(0, 2); 
        g.addEdge(2, 1); 
        g.addEdge(0, 3); 
        g.addEdge(1, 4); 
        
        g.dfs(0);
     }
 }