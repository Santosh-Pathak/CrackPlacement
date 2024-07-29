/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/

/**
 * Definition for singly-linked list.
 * struct ListNode *temp = list1;
 struct ListNode *temp2 = list2;
 {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
    {

        if (head1 == NULL && head2 == NULL)
        {
            return head2;
        }
        if (head1 == NULL)
        {
            return head2;
        }
        else if (head2 == NULL)
        {
            return head1;
        }

        // code here

        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        while (head1 != NULL && head2 != NULL)
        {
            temp1 = head1;
            temp2 = head2;
            // IF DATA OF FIRST LINKED LIST IS GREATER THA DATA F SECOND LINKED LIST
            if (head1->val > head2->val)
            {

                head2 = head2->next;
                // ADD THE SMALLER NODE TO THE FINAL LINKED LIST
                if (ansHead == NULL)
                {
                    ansHead = temp2;
                    ansTail = temp2;
                }
                else
                {
                    ansTail->next = temp2;
                    ansTail = temp2;
                }
                temp2->next = NULL;
            }
            else // IF DATA OF FIRST LINKED LIST IS SMALLER THAN DATA OF SECOND LINKED LIST
            {
                head1 = head1->next;
                // ADD THE SMALLER NODE TO THE FINAL LINKED LIST
                if (ansHead == NULL)
                {
                    ansHead = temp1;
                    ansTail = temp1;
                }
                else
                {
                    ansTail->next = temp1;
                    ansTail = temp1;
                }
                temp1->next = NULL;
            }
        }
        if (head1 != NULL)
        {
            ansTail->next = head1;
        }
        if (head2 != NULL)
        {
            ansTail->next = head2;
        }

        return ansHead;
    }
};