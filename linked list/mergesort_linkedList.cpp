 listnode* getMid(listnode* start,listnode* end)
 {
     struct ListNode* slow=start;
     struct ListNode* fast=start->next;
     while(fast!=end&&fast!=end->next)
     {
         slow=slow->next;
         fast=fast->next->next;
     }
     return slow;
 }
 listnode* merge(listnode* st1,listnode* st2)
 {
   struct ListNode* i1=st1;
    struct ListNode* i2=st2;
    struct ListNode* prev=NULL,*h=NULL;
    while(i1!=NULL&&i2!=NULL)
    {
        if(i1->val<i2->val)
        {
            if(prev==NULL)
            {
                h=i1;
            }
            prev=i1;
            i1=i1->next;
        }
        else
        {
            if(prev==NULL)
            {   h=i2;
                struct ListNode* temp=i2->next;
                h->next=i1;
                prev=h;
                i2=temp;
            }
            else
            {
              struct  ListNode* temp=i2->next;
                prev->next=i2;
                i2->next=i1;
                prev=prev->next;
                i2=temp;
            }
        }
    }
    if(i1==NULL)
        prev->next=i2;
    return h;
 }
 listnode* sort(listnode* head,listnode* start,listnode* end)
 {
    if(head == NULL)
    return NULL;
    if(start == end)
    return start;
    struct ListNode* mid = getMid(start,end);
    struct ListNode* start1 = mid->next;
    mid->next=NULL;
    struct ListNode* s1 = sort(head,start,mid);
    struct ListNode* s2 = sort(head,start1,end);
    return merge(s1,s2);
 }
listnode* sortList(listnode* a) {
   // int n = length(a);
    struct ListNode* curr=a;
    if(curr==NULL)
    return a;
    while(curr->next)
    {
        curr=curr->next;
    }
    struct ListNode* m = sort(a,a,curr);
    return m;
}

