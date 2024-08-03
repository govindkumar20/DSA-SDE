
class Solution {
public:
    long long count=0;
    long long sum=0;
    void dfs(TreeNode* root, long long targetSum){
        if(root==NULL) return;
        //sum+=root->val;
        if(root->val==targetSum) count++;
        dfs(root->left,targetSum-root->val);
        dfs(root->right,targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};