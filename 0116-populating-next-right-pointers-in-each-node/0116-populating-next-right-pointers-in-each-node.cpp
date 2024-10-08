class Solution {
public:
    vector<int> temp;
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                if(i<n-1) node->next=q.front();
                else node->next=NULL;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};