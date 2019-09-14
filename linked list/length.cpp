#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int length(struct node* h)
{
    struct node *curr=h;
    int i=0;
    while(curr)
    {
        i++;
        curr=curr->next;
    }
    return i;
}
void insertAtBeg(struct node** h,int d)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->next=*h;
    *h=n;
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
void insertAtPos(struct node** h,int d,int p)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(p==1)
    {
        newNode->data=d;
        newNode->next=*h;
        *h=newNode;
    }
    else
    {
        struct node *curr=*h;
        int i=1;
        while(curr&&i<p-1)
        {
            curr=curr->next;
            i++;
        }
        if(p<1||(curr==NULL))
        {

        }
        else
        {
            newNode->data=d;
            newNode->next=curr->next;
            curr->next=newNode;
        }
    }
}
int main()
{
    struct node *head = NULL;

	insertAtEnd(&head,1);
    insertAtBeg(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtBeg(&head,6);
    insertAtPos(&head,7,3);
    insertAtEnd(&head,8);
    insertAtBeg(&head,9);
   printf("\nlength of LL is %d",length(head));
}
