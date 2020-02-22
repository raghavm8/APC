import java.util.*;
public class Main
{
    int heap[];
    int size;
    int maxSize;
    final int front = 1;
    Main(int a)
    {
        size=0;
        maxSize=a;
        heap = new int[maxSize+1];
        heap[0] = Integer.MIN_VALUE;
    }
    public int parent(int pos)
    {
        return pos/2;
    }
    public int left(int pos)
    {
        return pos*2;
    }
    public int right(int pos)
    {
        return (2*pos)+1;
    }
    public boolean leaf(int pos)
    {
        if(pos>=(size/2) && pos<=size)
        return true;
        return false;
    }
    public void swap(int a,int b)
    {
        int y;
        y=heap[a];
        heap[a]=heap[b];
        heap[b]=y;
    }
    public void print() 
    { 
        for (int i = 1; i <= size / 2; i++) 
        { 
            System.out.print("PARENT : " + heap[i] + " LEFT CHILD : " + heap[2 * i] + " RIGHT CHILD :" + heap[2 * i + 1]); 
            System.out.println(); 
        } 
    } 
    public void heapify(int pos)
    {
        if(!leaf(pos))
        {
            if(heap[pos]>heap[left(pos)] || heap[pos]>heap[right(pos)])
            {
                if( heap[left(pos)] < heap[right(pos)] )
                {
                    swap(pos,left(pos));
                    heapify(left(pos));
                }
                else
                {
                    swap(pos,right(pos));
                    heapify(right(pos));
                }
            }
        }
    }
    public void insert(int x)
    {
        if(size>maxSize)
        {
            System.out.println("Heap full !!");
            return;
        }
        heap[++size] = x;
        int curr = size;
        while(heap[curr]<heap[parent(curr)])
        {
            swap(curr,parent(curr));
            curr=parent(curr);
        }
    }
    public void minHeap()
    {
        for(int i=size/2;i>=1;i--)
            heapify(i);
    }
    public int remove()
    {
        int x = heap[front];
        heap[front]=heap[size--];
        heapify(front);
        return x;
    }
	public static void main(String[] args) {
		Main minHeap = new Main(15); 
        minHeap.insert(5); 
        minHeap.insert(3); 
        minHeap.insert(17); 
        minHeap.insert(10); 
        minHeap.insert(84); 
        minHeap.insert(19); 
        minHeap.insert(6); 
        minHeap.insert(22); 
        minHeap.insert(9); 
        minHeap.minHeap(); 
  
        minHeap.print(); 
        int x = minHeap.remove();
        System.out.println("The removed element = " + x);
         minHeap.print(); 
	}
}
