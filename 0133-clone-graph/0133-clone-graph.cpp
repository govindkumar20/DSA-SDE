
/*

  1----------2
   | \       |
   |   \     |
   |     \   |
   |       \ |    
   4 --------3

   map<Node*,Node*> 
   1-1'
   2-2'
   3-3'
   4-4'

   1'-2'3'4'
   2'-1'3'
   3'-1'2'4'
   4'-1'3'
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL; // if node is empty
        unordered_map<Node*,Node*> vis;
        queue<Node*> q;
        q.push(node);
        vis[node]=new Node(node->val);
        
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            for(Node* i:curr->neighbors){
                if(!vis[i]){
                    vis[i]=new Node(i->val);
                    q.push(i);
                }
                vis[curr]->neighbors.push_back(vis[i]);
            }
        }
      return vis[node];
    }
};