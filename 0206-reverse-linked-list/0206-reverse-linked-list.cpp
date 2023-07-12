
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        while(head!=NULL)
        {
            ListNode* fwd=head->next;
            head->next=prev;
            prev=head;
            head=fwd;
        }
        return prev;
    }
};