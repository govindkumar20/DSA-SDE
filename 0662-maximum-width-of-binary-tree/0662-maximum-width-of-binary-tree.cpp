
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0}); // node,index
        long long ans=0;
        while(!q.empty()){
            long long start=q.front().second;
            long long end=q.back().second;
            ans=max(ans,end-start+1);
            long n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                int index=q.front().second;
                q.pop();
                if(node->left) q.push({node->left,(long long)2*index+1});
                if(node->right) q.push({node->right,(long long)2*index+2});
            }
        }
        return ans;
    }
};