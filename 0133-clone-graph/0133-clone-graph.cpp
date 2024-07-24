/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> m;
        Node* newNode=new Node(node->val,{});
        queue<Node*> q;
        q.push(node);
        m[node]=newNode;
        while(!q.empty()){
            Node* cur=q.front();
            q.pop();
            for( Node* i:cur->neighbors){
                if(m.find(i)==m.end()){
                    m[i]=new Node(i->val,{});
                    q.push(i);
                }
                m[cur]->neighbors.push_back(m[i]);
            }
        }
        return newNode;
    }
};