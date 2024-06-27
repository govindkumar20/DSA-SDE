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
    int dfs(TreeNode* root,int & flag){
        if(root==NULL) return 0;
        int left=dfs(root->left,flag)+1;
        int right=dfs(root->right,flag)+1;
        if(abs(left-right)>1) flag=0;
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int flag=1;
         dfs(root,flag);
        if(flag) return true;
        else return false;

    }
};