import java.util.*;
import java.lang.*;
public class Main
{
	public static void main(String[] args) {
        String s = new String("HellOWorlD");
        String ans = new String();
        int n=s.length();
        System.out.println(s);
        for(int i=0;i<n;i++)
        {
            char c = s.charAt(i);
            if(Character.isLowerCase(c))
                {
                    char d = Character.toUpperCase(c);
                    ans = ans + d;
                } 
            else if(Character.isUpperCase(c))
                {
                    char d = Character.toLowerCase(c);
                    ans = ans + d;
                }
        }
        System.out.print(ans);
	}
}
