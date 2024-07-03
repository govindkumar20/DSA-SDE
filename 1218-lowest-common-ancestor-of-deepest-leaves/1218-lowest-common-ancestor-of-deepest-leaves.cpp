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
public:  int d=0;
    int depth(TreeNode* root){ // depth calculator func
        if(root==NULL) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;

        int left=depth(root->left); // left subtree depth
        int right=depth(root->right); // right subtree depth
        
        if(left==right) return root; // if both equal means root is lca
        else if(left>right) return lcaDeepestLeaves(root->left); // bcz we want to reach deepest leaves so choose longer depth
        else return lcaDeepestLeaves(root->right);
    }
};