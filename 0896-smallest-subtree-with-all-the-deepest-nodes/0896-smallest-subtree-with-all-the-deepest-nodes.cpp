
class Solution {  
public: int dfs(TreeNode* root){
    if(root==NULL) return 0;
    return max(dfs(root->left),dfs(root->right))+1;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==right) return root;
        else if(left>right) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);

    }
};