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
    int flag=0;
    void dfs(TreeNode* root,int curr_sum,int targetSum){
        if(root==NULL) return;
        if(root->left || root->right){
            curr_sum+=root->val;
        }
        else {
            curr_sum+=root->val;
            if(curr_sum==targetSum) {
                flag=1;
                
            }
        }
        dfs(root->left,curr_sum,targetSum);
        dfs(root->right,curr_sum,targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr_sum=0;
        dfs(root,curr_sum,targetSum);
        if(flag==1) return true;
        else return false;
        
    }
};