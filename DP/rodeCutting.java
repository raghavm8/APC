/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class Main
{
    static int max(int a,int b)
    {
        return a>b?a:b;
    }
  static int cut(int arr[],int n)
  {
      int ans[] = new int[n+1];
      ans[0]=0;
      int maxValue = Integer.MIN_VALUE;
      for(int i=1;i<=n;i++)
      { 
          int max = Integer.MIN_VALUE;
          for(int j=0;j<i;j++)
          {
              maxValue = max(maxValue,arr[j]+ans[i-j-1]);
          }
          ans[i] = maxValue;
      }
      return ans[n];
  }
	public static void main(String[] args) {
	    Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		arr[i] = s.nextInt();
		System.out.println("Maximum Obtainable Value is " + cut(arr, n));
	}
}
