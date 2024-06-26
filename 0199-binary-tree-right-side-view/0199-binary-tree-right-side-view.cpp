
class Solution {
public:  
queue<TreeNode*> q;
vector<int> v;
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return v;
          q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
            }
            v.push_back(level.back());
        }
        
       
       return v;
    }
};
