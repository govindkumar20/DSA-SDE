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
     int xd,yd,xp,yp;
     void depth(TreeNode* root,int x, int y,int d,int p){
      if(root==NULL) return;
      if(root->val==x){ // if we found x
             xd=d;
             xp=p;
             return;
      } if(root->val==y){  // if we found y
        yd=d;
        yp=p;
        return;
      }
      depth(root->left,x,y,d+1,root->val);
      depth(root->right,x,y,d+1,root->val);

     }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
       depth(root,x,y,0,0);
       if(xd==yd && xp!=yp) return true;
       return false;

    }
};