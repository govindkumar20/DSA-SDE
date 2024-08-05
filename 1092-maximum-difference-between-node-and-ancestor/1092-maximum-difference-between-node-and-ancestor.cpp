/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MIN;
    void dfs(TreeNode* root, TreeNode* ancestor){
        if(root==NULL) return;
        ans=max(ans,abs(ancestor->val-root->val));
        dfs(root->left,ancestor);
        dfs(root->right,ancestor);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root,root);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return ans;
    }
};