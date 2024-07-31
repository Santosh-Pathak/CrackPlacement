
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

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if (head == nullptr || n <= 0) {
//             return head;
//         }

//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;
//         ListNode* fast = dummy;
//         ListNode* slow = dummy;

//         // Move fast n+1 steps ahead
//         for (int i = 0; i < n + 1; i++) {
//             if (fast == nullptr) {
//                 // This means n is equal to the length of the list,
//                 // so remove the first node (dummy's next).
//                 ListNode* toRemove = dummy->next;
//                 dummy->next = dummy->next->next;
//                 delete toRemove;
//                 return dummy->next;
//             }
//             fast = fast->next;
//         }

//         // Move both fast and slow until fast reaches the end
//         while (fast != nullptr) {
//             fast = fast->next;
//             slow = slow->next;
//         }

//         // Remove the nth node from the end
//         ListNode* toRemove = slow->next;
//         slow->next = slow->next->next;
//         delete toRemove;

//         return dummy->next;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
            return head;
        }

        ListNode* prev =head,*temp=head;
        while(n)
        {
            temp=temp->next;
            n--;
        }
        if(temp==NULL)return head->next;
        while(temp != NULL &&  temp->next!=NULL)
        {
            temp=temp->next;
            prev=prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};












