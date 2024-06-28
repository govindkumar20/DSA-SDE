
class Solution {
public:
  long long count=0;
   long long sum=0;
    void dfs(TreeNode* root,long long targetSum,long long& count){
        if(root==NULL) return;
         sum+=root->val;
             if(root->val==targetSum){
                count++;
             } 
             dfs(root->left,targetSum-root->val,count);
             dfs(root->right,targetSum-root->val,count);
    }

 
    long long pathSum(TreeNode* root, long long targetSum) {
        if(root==NULL) return 0;
      
        dfs(root,targetSum,count);
         pathSum(root->left,targetSum);
         pathSum(root->right,targetSum);
         return count;
    }
};