import java.util.*;
class Main{
    int v=9;
    int minDist(int[] d,boolean[] vis)
    {
        int min=Integer.MAX_VALUE, minIndex=-1;
        for(int i=0;i<v;i++)
        {
            if(vis[i]==false&& d[i] <= min)
            {
                min=d[i];
                minIndex=i;
            }
        }
        return minIndex;
    }
    int[] dijkstra(int a[][], int src)
    {
        int dist[] = new int[v];
        boolean vis[] = new boolean[v];
        for(int i=0;i<v;i++)
        {
            dist[i] = Integer.MAX_VALUE;
            vis[i] = false;
        }
        dist[src]=0;
        for(int i=0;i<v-1;i++)
        {
            int u = minDist(dist,vis);
            vis[u] = true;
            for(int j=0;j<v;j++)
            {
                if(vis[j]!=true && dist[u]!=Integer.MAX_VALUE && a[u][j]!=0 && dist[j]>dist[u]+a[u][j])
                    dist[j]=dist[u]+a[u][j];
            }
        }
        return dist;
    }
     public static void main(String[] args) 
     { 
         
        int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
        Main t = new Main(); 
      int[] ans = t.dijkstra(graph, 0); 
    
        for (int i = 0; i < t.v; i++) 
            System.out.println(i + " tt " + ans[i]);
     } 
}