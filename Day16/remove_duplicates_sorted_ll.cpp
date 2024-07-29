//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<bits/stdc++.h>

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL)
        return head;
    
      struct ListNode *curr =head;
    
    while(curr != NULL)
    {
        if((curr->next !=NULL) && curr->val==curr->next->val )
        {
            struct ListNode *newnext =curr->next->next;
            struct ListNode *delete=curr->next;
            free(delete);
            curr->next=newnext;
        }
        else
        {
            curr  = curr ->next;
        }
    }
    return head;
}