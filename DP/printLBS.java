import java.util.*;
class Main
{
    static void print(ArrayList<Integer> a,int n)
    {
        for(int i=0;i<n;i++)
        System.out.print(a.get(i) + " ");
    }
  static void printLBS (int[]a, int n)
  {
    ArrayList<Integer> lis[] = new ArrayList[n];
    ArrayList<Integer> lds[] = new ArrayList[n];
    
    for (int i = 0; i < n; i++)
    {
        lis[i] = new ArrayList<Integer>();
        lds[i] = new ArrayList<Integer>();
    }
    
    lis[0].add(a[0]);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && lis[j].size()>lis[i].size())
            {
                for(int k : lis[j])
                if (!lis[i].contains(k)) 
                    lis[i].add(k); 
            }
        }
        lis[i].add(a[i]);
    }
    lds[n-1].add(a[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[i]>a[j] && lds[j].size()>lds[i].size())
            {
                for(int k : lds[j])
                if (!lds[i].contains(k)) 
                    lds[i].add(k); 
            }
        }
        lds[i].add(a[i]);
    }
    for (int i = 0; i < n; i++) 
        Collections.reverse(lds[i]); 
    
  int max=0,maxIndex=-1;
        for(int i=0;i<n;i++)
        {
            if( max<(lis[i].size()+lds[i].size()-1) )
            {
                max = lis[i].size()+lds[i].size()-1;
                maxIndex=i;
            }
        }
        print(lis[maxIndex],lis[maxIndex].size()-1);
        print(lds[maxIndex],lds[maxIndex].size());
  }
  public static void main (String[]ada)
  {
    //int[] arr = { 1, 11, 2, 10, 4, 5, 2, 1 };
    //int n = arr.length;
    int n;
    
    Scanner s = new Scanner(System.in);
    n = s.nextInt();
    int arr[] = new int[n];
    
    for(int i=0;i<n;i++)
    arr[i] = s.nextInt();
    
    printLBS (arr, n);
  }
}
