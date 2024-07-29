//Given the head of a singly linked list, reverse the list, and return the reversed list.
//Approch 1-> USING # POINTERs
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         struct ListNode *prev,*current,*next;
    prev=0;
    current=next=head;
    while(next!=0)
    {
        next=next->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
    
    }
};
//APPROACH NO-2  USING RECURSION