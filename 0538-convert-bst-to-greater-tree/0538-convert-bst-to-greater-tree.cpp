
class Solution {
public:

    void revInorder(TreeNode* root, int &sum){
        if(root==NULL) return ;
        revInorder(root->right,sum);
        sum+=root->val;
        root->val=sum;
        revInorder(root->left,sum);
       
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
         revInorder(root,sum);
         return root;
    }
};