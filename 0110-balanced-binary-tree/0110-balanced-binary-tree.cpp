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
      int bfs(TreeNode* root, int & height){
        if(root==NULL) return 0;
        int left=bfs(root->left,height)+1;
        int right=bfs(root->right,height)+1;
        if(abs(left-right)>1) height=0;
        return max(left,right);
        
      }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;  // single node is always balanced
        int height=1; 
         bfs(root,height);   // the moment diff of left and right subtree heights exceeds 1 
         if(height) return true;// height will change to 0
         else return false;   // if height is zero return false else if there is some value of height return true
    }
};