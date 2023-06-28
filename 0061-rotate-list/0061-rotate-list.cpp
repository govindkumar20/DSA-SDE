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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        {
             return head;
        }
        ListNode* temp=head;
        int n=0;
        while(temp->next)    //reaching last node
        {
            temp=temp->next;
            n++;
        }
        temp->next=head;            // last pointing to head
       k=k%(n+1);        //if k>size and n+1 is size of ll
        int jump=n-k;
         temp=head;
        while(jump)
        {
            temp=temp->next;
            jump--;
        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        return newhead;
    }
};