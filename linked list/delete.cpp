#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
};
void deleteAtBeg(struct node **h)
{
   struct node *c=*h;
   *h=c->next;
}
void deleteAtEnd(struct node **h)
{
    struct node *curr=*h;
    while(curr&&curr->next&&curr->next->next)
    {
        curr=curr->next;
    }
    curr->next=NULL;

}
void deleteAtPos(struct node **h,int p)
{
    struct node *c=*h;
    if(p==1)
    {
        *h=c->next;
    }
    else
    {
        int i=1;
        while(c&&i<p-1)
        {
            c=c->next;
            i++;
        }
        if(p<1||(c==NULL&&c->next==NULL))
        {
             //commented for sum test case but to be written;
        }
        else
        {
            c->next=c->next->next;
        }
    }
}
void insertAtEnd(struct node** h,int d)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=NULL;
    if(*h==NULL)
        *h=n;
    else
    {
        struct node *curr=*h;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=n;
    }
}
void print(struct node** h)
{
	struct node *curr=*h;
    while(curr)
    {
        printf("%d->%u\n",curr->data,curr->next);
        curr=curr->next;
    }
}
int main()
{
    struct node *head = NULL;
    int i=0;

    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    insertAtEnd(&head,7);
    insertAtEnd(&head,8);
    insertAtEnd(&head,9);
    print(&head);
    printf("\n\n\n\n");
	deleteAtBeg(&head);
 	deleteAtEnd(&head);
    deleteAtPos(&head,4);
  print(&head);
}
