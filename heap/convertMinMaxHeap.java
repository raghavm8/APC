import java.util.*;
class Main
{
  public static void maxHeapify (int heap[], int n, int i)
  {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && heap[l] > heap[i])
        largest = l;
    if (r < n && heap[r] > heap[largest])
        largest = r;
    if (largest != i)
      {
	int x = heap[i];
	  heap[i] = heap[largest];
	  heap[largest] = x;
	  maxHeapify (heap, n, largest);
      }
  }
  public static void minHeapify(int heap[],int n,int i)
  {
      int l = 2*i+1;
      int r = 2*i+2;
      int smallest = i;
      if(l<n&&heap[l]<heap[i])
      smallest = l;
      if(r<n&&heap[r]<heap[smallest])
      smallest = r;
      if(smallest!=i)
      {
          int x=heap[i];
          heap[i] = heap[smallest];
          heap[smallest]=x;
          minHeapify(heap,n,smallest);
      }
  }
  public static void convertMaxHeap (int heap[], int size)
  {
    for (int i = size / 2; i >= 0; i--)
      maxHeapify (heap, size, i);
  }
  public static void convertMinHeap(int heap[], int size)
  {
      for(int i=size/2;i>=0;i--)
      minHeapify(heap,size,i);
  }
  public static void print (int heap[], int size)
  {
    for (int i = 0; i < size; i++)
      {
	System.out.print (heap[i] + " ");
      }
    System.out.println ();
  }
  public static void main (String[]ad)
  {
    System.out.println("Enter array size");
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    
    int arr[] = new int[n];
    System.out.println("Enter array elements ");
    for(int i=0;i<n;i++)
    arr[i] = s.nextInt();
   // int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}; 
 //    int n = arr.length; 
    System.out.print ("Heap array : ");
    print (arr, n);

    convertMaxHeap (arr, n);

    System.out.print ("Max Heap array : ");
    print (arr, n);
    
    System.out.print("Min Heap array : ");
    convertMinHeap(arr,n);
    print(arr,n);
    
  }
}
