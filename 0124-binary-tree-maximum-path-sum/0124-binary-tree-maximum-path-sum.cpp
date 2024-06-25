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
     int dfs(TreeNode* root,int &  s){
       if(root==NULL) return 0;
       int left=max(0,dfs(root->left,s));
       int right=max(0,dfs(root->right,s));
       s=max(s,root->val+left+right);

       return  root->val+max(left,right);
     }
    int maxPathSum(TreeNode* root) {
        int s=INT_MIN;
        dfs(root,s);
        return s;
    }
};