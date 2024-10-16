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
    bool flag=0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int lh=dfs(root->left);
        int rh=dfs(root->right);
        if(abs(lh-rh)>1) flag=1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag?false:true;
    }
};