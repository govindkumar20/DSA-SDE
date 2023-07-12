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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* merged=NULL;
        for(auto i:lists)
        {
            merged=merge(merged,i);
        }
        return merged;
    }

    ListNode* merge(ListNode* l1,ListNode* l2)
    {
       if(l1==NULL) return l2;
       if(l2==NULL) return l1;
       if(l1->val<=l2->val)
       {
           l1->next=merge(l1->next,l2);
           return l1;
       }
       else if(l1->val>l2->val)
       {
           l2->next=merge(l1,l2->next);
           return l2;
       }
       return {};
    }
};