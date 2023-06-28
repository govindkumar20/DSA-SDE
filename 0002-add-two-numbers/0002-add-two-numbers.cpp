
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(0);
        int sum=0;
        int carry=0;
        ListNode* head=l3;
        while(l1 && l2)             //l1 and l2 of same length
        {
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            l3->next=new ListNode(sum%10);
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1)                         // l1 length greater than l2
        {
            sum=l1->val+carry;
            carry=sum/10;
            l3->next=new ListNode(sum%10);
            l3=l3->next;
            l1=l1->next;
           
        }
        while(l2)                              // l2 length greater than l1
        {
            sum=l2->val+carry;
            carry=sum/10;
            l3->next=new ListNode(sum%10);
            l3=l3->next;
            l2=l2->next;
        }
        if(carry)                                //if there exist carry at end
        {
            l3->next=new ListNode(carry);
        }
        return head->next;
    }
};