
class Solution {
public:
     void dfs(TreeNode* root1,TreeNode* root2,int level){
        if(root1==NULL) return;
        if(level%2==0) swap(root1->val,root2->val);
        dfs(root1->left,root2->right,level+1);
        dfs(root1->right,root2->left,level+1);
     }
    TreeNode* reverseOddLevels(TreeNode* root) {
       dfs(root->left,root->right,0);
       return root;

    }
};