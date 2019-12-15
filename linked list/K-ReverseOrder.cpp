52 ms	1760 KB
×
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * typedef struct ListNode listnode;
 *
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list
 * @input B : Integer
 *
 * @Output head pointer of list.
 */
listnode* reverseList(listnode* A, int b) {
    struct ListNode* curr=A;
    struct ListNode* nextt=NULL;
    struct ListNode* prev = NULL;
    int i=0;
    while(curr&&i<b)
    {
       nextt = curr->next;
       curr->next=prev;
       prev=curr;
       curr=nextt;
       i++;
    }
    if(nextt!=NULL)
    {
        A->next = reverseList(nextt,b);
    }
    return prev;
}
