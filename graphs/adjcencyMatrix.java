import java.util.*;
class Main{
    int v;
    int mat[][];
    
    Main(int b)
    {
        v=b;
        mat = new int[v][v];
    }
    void addEdge(int u,int v)
    {
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    void print()
    {
        int i,j;
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                System.out.print(mat[i][j]);
            }
            System.out.println();
        }
        
        for(i=0;i<v;i++)
        {
            System.out.print(i + ": ");
            for(j=0;j<v;j++)
            {
                if(mat[i][j] == 1)
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
    public static void main(String [] afw){
        Main graph = new Main(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 4);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);
        
        graph.print();
    }
}