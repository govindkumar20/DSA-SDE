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
     vector<int> ans;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int mn=INT_MAX;
        for(int i=1;i<ans.size();i++){
         int temp=ans[i]-ans[i-1];
         if(temp<mn) mn=temp;
        } 
        return mn;
    }
};