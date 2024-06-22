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
     int dfs(TreeNode* root, int& d){
        if(root==NULL) return 0;
        int left=dfs(root->left,d);
        int right=dfs(root->right,d);
        d=max(d,left+right);// max diameter so far
        return 1+max(left,right);// height of curr node
     }


    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        dfs(root,d);
        return d;
    }
};