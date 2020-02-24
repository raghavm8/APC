/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Main
{
   static void subsets(char[] s)
    {
        int i,j;
        int n = s.length;
        
        for(i=0;i<(1<<n);i++)
        {
            for(j=0;j<n;j++)
            if((i&(1<<j))>0)
            System.out.print(s[j]);
            System.out.println();
        }
    }
	public static void main(String[] args) {
	char set[] = {'a', 'b', 'c'}; 
       subsets(set); 
	}
}
