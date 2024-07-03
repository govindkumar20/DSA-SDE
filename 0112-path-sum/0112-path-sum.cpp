
class Solution {
public:
        int sum=0;
        bool flag=0;
        void dfs(TreeNode* root,int targetSum){
            if(root==NULL) return ;
            int prev=sum;
            if(root->left || root->right){
                sum+=root->val;
            } else{
               sum+=root->val;
               if(sum==targetSum) flag=1;
            }
            dfs(root->left,targetSum);
            dfs(root->right,targetSum);
            sum=prev;
        }
    bool hasPathSum(TreeNode* root, int targetSum) {
       dfs(root,targetSum);
       return flag;

        
    }
};