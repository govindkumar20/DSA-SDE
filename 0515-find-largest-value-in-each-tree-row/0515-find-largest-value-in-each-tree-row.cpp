
class Solution {
public:
    vector<int> ans;
    queue<TreeNode*> q;
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                maxi=max(maxi,node->val);
               // level.push_back(node->val); 
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};