import java.util.*;
public class Main
{
    static class wcv{
        int weight,value;
        double cost;
        wcv(int w,int v)
        {
            weight = w;
            value = v;
            cost = new Double(v/w);
        }
    }
    static double getMaxValue(int[] wt,int[] val,int c)
    {
        wcv[] x = new wcv[wt.length];
        for(int i=0;i<wt.length;i++)
            x[i] = new wcv(wt[i],val[i]);
        
        Arrays.sort(x,new Comparator<wcv>(){
           public int compare(wcv a,wcv b)
            {
               if(a.cost>b.cost)
               return -1;
               else if(a.cost<b.cost)
               return 1;
               else return 0;
            }
        });
        double d=0d;
        /*for(int i=0;i<x.length;i++)
          System.out.println(x[i].cost);*/
        for(int i=0;i<x.length;i++)
        {
            if(x[i].weight<=c)
            {
                d = d + x[i].value;
                c = c - x[i].weight;
            }
            else{
                double f = (double)c/(double)x[i].weight;
                d = d + x[i].value*f;
                break;
            }
            //System.out.println("d = " + d + " c = " + c);
        }
        return d;
    }
	public static void main(String[] args) {
	    int[] wt = {10, 40, 20, 30}; 
        int[] val = {60, 40, 100, 120}; 
        int capacity = 50; 
        double maxValue = getMaxValue(wt, val, capacity); 
        System.out.println("Maximum value we can obtain = " + maxValue); 
	}
}
