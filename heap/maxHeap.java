class Main
{
    int size;
    int maxSize;
    int heap[];
    final int front = 1;
    Main(int s)
    {
        size=0;
        maxSize=s;
        heap = new int[maxSize+1];
        heap[0]=Integer.MAX_VALUE;
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
        return (pos*2)+1;
    }
    public boolean leaf(int pos)
    {
        if(pos>=size/2 && pos<=size)
        return true;
        return false;
    }
    public void swap(int a,int b)
    {
        int x;
        x = heap[a];
        heap[a] = heap[b];
        heap[b] = x;
    }
    public void heapify(int pos)
    {
        if(!leaf(pos))
        {
            if( heap[pos]<heap[left(pos)] || heap[pos]<heap[right(pos)] )
            {
                if(heap[left(pos)]>heap[right(pos)])
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
    public void maxHeap()
    {
        for(int i=size/2;i>=1;i--)
        {
            heapify(i);
        }
    }
    public void insert(int x)
    {
        if(size > maxSize)
        {
            System.out.println("Heap full !!");
            return;
        }
        heap[++size] = x;
        int curr = size;
        while(heap[curr]>heap[parent(curr)])
        {
            swap(curr,parent(curr));
            curr = parent(curr);
        }
    }
    public int remove()
    {
        int x = heap[front];
        heap[front] = heap[size--];
        heapify(front);
        return x;
    }
    public void print()
    {
        for(int i=1;i<=size/2;i++)
        {
            System.out.print(" PARENT : " + heap[i] + " LEFT CHILD : " + heap[2 * i] + " RIGHT CHILD :" + heap[2 * i + 1]); 
            System.out.println(); 

        }
    }
    public static void main(String[] ar)
    {
        Main maxHeap = new Main(15); 
        maxHeap.insert(5); 
        maxHeap.insert(3); 
        maxHeap.insert(17); 
        maxHeap.insert(10); 
        maxHeap.insert(84); 
        maxHeap.insert(19); 
        maxHeap.insert(6); 
        maxHeap.insert(22); 
        maxHeap.insert(9);
        maxHeap.maxHeap();
  
        maxHeap.print(); 
        int x = maxHeap.remove();
        System.out.print(x);
    }
}