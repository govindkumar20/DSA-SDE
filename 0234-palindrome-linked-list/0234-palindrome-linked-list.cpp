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
     ListNode* middle(ListNode* head)           //finding mid point
     {
         ListNode* slow=head;
         ListNode* fast=head;
         while(fast->next!=NULL && fast->next->next!=NULL)
         {
             slow=slow->next;
             fast=fast->next->next;
         }
         return slow;
     }

     ListNode* reverse(ListNode* head)              // reversing 2nd half
     {
         ListNode* prev=NULL;
         ListNode* fwd=NULL;
         while(head!=NULL)
         {
             fwd=head->next;
             head->next=prev;
             prev=head;
             head=fwd;
         }
         return prev;
     }

    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        ListNode* mid=middle(head);
        ListNode* last=reverse(mid->next);

        ListNode* curr=head;
        while(last!=NULL)                 // now comparing
        {
            if(curr->val!=last->val)
            {
                return false;
            }
            last=last->next;
            curr=curr->next;
        }
        return true;
    }
};