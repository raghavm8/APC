import java.util.*;
class Main
{
    static class select
    {
        int start;
        int finish;
        char id;
        select(char c,int s,int f)
        {
            id = c;
            start = s;
            finish = f;
        }
    }
    static void find(select[] s)
    {
        Arrays.sort(s,new Comparator<select>(){
            public int compare(select a,select b)
            {
                if(a.finish > b.finish)
                return 1;
                else if(a.finish<b.finish)
                return -1;
                else return 0;
            }
        });
        int i=0;
        String res = "";
        res = res + s[i].id;
        int count=1;
        for(int j=1;j<s.length;j++)
        {
            if(s[i].finish <= s[j].start)
            {
                res += s[j].id;
                count++;
                i=j;
            }
        }
        System.out.println(count  + " jobs = " + res);
    }
    public static void main(String[] ada)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int st,fin;
        select[] sel = new select[n];
        for(int i=0;i<n;i++)
        {
            char d = s.next().charAt(0);
            st = s.nextInt();
            fin = s.nextInt();
            sel[i] = new select(d,st,fin);
        }
        find(sel);
    }
}