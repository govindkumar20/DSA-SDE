
class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
          if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
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
            
                ans.push_back(level.back());
             
            }
            
        
        return ans;
    }
};