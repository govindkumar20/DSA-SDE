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
public: int sum=0;
      int dfs(TreeNode* root, int& tilt){
        if(root==NULL) return 0;
           int left=dfs(root->left,tilt);
           int right=dfs(root->right,tilt);
           tilt+=abs(left-right);
           return left+right+root->val;
      }


    int findTilt(TreeNode* root) {
          int tilt=0;
          dfs(root,tilt);
          return tilt;


    }
};