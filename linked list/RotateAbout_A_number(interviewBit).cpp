int length(listnode* a)
 {
     int i=0;
     struct ListNode* curr=NULL;
    curr = a;
     while(curr)
     {
         curr = curr->next;
         i++;
     }
        return i;
 }
 listnode* reverse(listnode* a)
 {
    struct ListNode* curr = a;
    struct ListNode* prev = NULL;
    struct ListNode* nextt = NULL;
     while(curr)
    {
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }
    return prev;
 }
listnode* rotateRight(listnode* a, int b) {
    struct ListNode* curr = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* nextt = NULL;
    int x,i=0,l;
    l = length(a);
  //  printf("length = %d\n",l);
    x = (l-b%l);
    curr = a;
    //printf("length = %d\n",x);
    if(l==1 || l==x)
    return a;
    while(curr && i<x)
    {
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
        i++;
    }
    struct ListNode* rev = reverse(prev);
    struct ListNode* curr1 = curr;
    while(curr1)
    {
        if(!curr1->next)
        {
           curr1->next = rev;
           break;
        }
        else
        curr1 = curr1->next;
    }
    return curr;
}

