import java.util.*;
class code
{
    int data;
    char c;
    code left;
    code right;
    code (){}
    code(int d,char ch)
    {
        data = d;
        c=ch;
    }
}
class cmp implements Comparator<code>
{
    public int compare(code a,code b)
    {
        if(a.data>b.data)
        return 1;
        else if(a.data<b.data)
        return -1;
        else return 0;
    }
}
public class Main
{
    static void getCode(code root,String s)
    {
        if(root.left==null&&root.right == null&&Character.isLetter(root.c))
        {
            System.out.println(root.c + " " + s);
            return;
        }
        getCode(root.left,s+"0");
        getCode(root.right,s+"1");
    }
    static void getTree(PriorityQueue<code> q)
    {
        code root = new code();
      while(q.size()>1)
      {
          code x = q.poll();
          code y = q.poll();
          code f = new code();
          f.data = x.data + y.data;
          f.c = '-';
          f.left = x;
          f.right = y;
          root = f;
          q.add(f);
      }
      getCode(root,"");
    }
    public static void main(String[] adi)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        
        char[] ch = new char[n];
        for(int i=0;i<n;i++)
        ch[i] = s.next().charAt(0);
        
        int[] f = new int[n];
        for(int i=0;i<n;i++)
        f[i] = s.nextInt();
        
        PriorityQueue<code> q = new PriorityQueue<code>(n,new cmp());
        for(int i=0;i<n;i++)
        {
           code c = new code(f[i],ch[i]);
           q.add(c);
        }
        getTree(q);
    }
}