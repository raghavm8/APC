#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
};
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
struct node* reverse(struct node* curr)
{
	//printf("this is reverse function\n");
	struct node *first,*second;
	first = curr;
	if(first)
	second = first->next;
	if(!second)
	return first;
	else
	{
		struct node *h = reverse(second);
		first->next=second->next;
        second->next=first;
        return h;
	}

	/*struct node *temp = NULL;
	struct node *curr = *h;
	struct node *nextt = curr->next;
	while(curr)
	{
	  curr->next = temp;
	  temp =  curr;
	  curr = nextt;
	  nextt = curr->next;
	}
	return curr;*/
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
	struct node *head1 = NULL;
	head1 = reverse(head);
	printf("\n");
    print(&head1);
    return 0;
}
