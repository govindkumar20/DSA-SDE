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
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }

int height(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return (lh==-1 || rh==-1 || abs(lh-rh)>1)?-1:max(lh,rh)+1;
}
};