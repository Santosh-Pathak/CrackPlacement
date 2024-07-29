/*Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
The most significant bit is at the head of the linked list.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<bits/stdc++.h>
using namespace std;
int getDecimalValue(struct ListNode* head){
    int num=0,sum=0;
    struct ListNode *temp,*temp2;
    temp=temp2=head;
    while(temp!=NULL)
    {
        num++;
        temp=temp->next;
    }
    for(int i=num-1;temp2!=NULL;i--)
    {
        sum= sum + (temp2->val)* pow(2,i);
        temp2=temp2->next;
    }
    return sum;
}