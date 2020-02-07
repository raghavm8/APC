#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
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
	//printf("%d\n",**h);
   //int i=0;
	if(*h==NULL)
    *h=n;
    else
    {
        struct node *curr=*h;
        while(curr->next!=NULL)
        {
        //	i++;
        curr=curr->next;
        }
        curr->next=n;
    }
   // printf("%d\n",i);
}
void insertAtPos(struct node** h,int d,int p)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
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
    struct node* head = NULL;
	insertAtEnd(&head,1);
    insertAtBeg(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtBeg(&head,6);
    //printf("%d\n",head->next);
    insertAtPos(&head,7,3);
    insertAtEnd(&head,8);
    insertAtBeg(&head,9);
    print(&head);
    printf("\n\n\n\n");
}
