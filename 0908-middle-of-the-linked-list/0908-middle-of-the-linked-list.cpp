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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        if(len%2==0)
        {
           return slow->next;
        }
        return slow;

    }
};