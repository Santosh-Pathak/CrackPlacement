

/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.


 */

#include<bits/stdc++.h>
using namespace std;

int length(struct ListNode *head)
{
    int l = 0;
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{

    int l1 = length(headA);
    int l2 = length(headB);
    int d = 0;
    struct ListNode *p1;
    struct ListNode *p2;

    if (l1 > l2)
    {
        d = l1 - l2;
        p1 = headA;
        p2 = headB;
    }
    else
    {
        d = l2 - l1;
        p1 = headB;
        p2 = headA;
    }

    while (d)
    {
        p1 = p1->next;
        if (p1 == NULL)
            return NULL;
        d--;
    }
    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
            return p1;

        p1 = p1->next;
        p2 = p2->next;
    }

    return 0;
}