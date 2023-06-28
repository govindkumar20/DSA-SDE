
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        map<Node*,Node*> m;
        while(temp!=NULL)
        {
            m[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            m[temp]->next=m[temp->next];
            m[temp]->random=m[temp->random];
            temp=temp->next;
        }
        return m[head];

    }

};