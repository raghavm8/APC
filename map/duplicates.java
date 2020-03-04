/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class Main
{
    static int[] dupS(int[] a,int n)
    {
        int k=0;
        int ans[] = new int[3];
        for(int i=0;i<n;i++)
        {
            if(a[Math.abs(a[i])]>0)
            a[Math.abs(a[i])] *= -1;
            else
            ans[k++]=Math.abs(a[i]);
        }
        return ans;
    }
    static ArrayList<Integer> dup(int[] a,int n)
    {
        Map<Integer,Integer> m = new HashMap<Integer,Integer>();
        for(int i=0;i<n;i++)
        {
            if(m.containsKey(a[i]))
            m.replace(a[i],m.get(a[i])+1);
            else
            m.put(a[i],1);
        }
        int j=0;
        ArrayList<Integer> ans = new ArrayList<Integer>(); 
        /*System.out.print(m);
        System.out.println();*/
        for(Integer c :m.keySet())
        {
            if(m.get(c)>1)
            ans.add(c);
        }
        return ans;
    }
	public static void main(String[] args) {
		int arr[] = {1, 2, 3, 1, 3, 6, 6}; 
        int arr_size = arr.length; 
        // using ArrayList
        /*ArrayList<Integer> ans = dup(arr, arr_size); 
        for(int i=0;i<ans.size();i++)
        System.out.print(ans.get(i));*/
        // no extra space 
        int[] ans = dupS(arr, arr_size);
         for(int i=0;i<ans.length;i++)
        System.out.print("duplicate ele : "+ans[i]+" ");
	}
}
