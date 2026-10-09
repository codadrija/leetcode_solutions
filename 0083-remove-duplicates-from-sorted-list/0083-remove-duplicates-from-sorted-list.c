/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode* temp= head;
    while(temp!= NULL && temp->next!=NULL)
    {
        struct ListNode* nextnode= temp->next;
        while(nextnode!=NULL && nextnode->val== temp->val)
        {
            nextnode=nextnode->next;
        }
        temp->next=nextnode;
        temp= nextnode;
    }
    return head;
}