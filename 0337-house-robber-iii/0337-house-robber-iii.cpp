
class Solution {
public:
   int robbing(TreeNode* root, int& nl , int& nr){
    if(root==NULL) return 0;
    int nll=0,nlr=0,nrl=0,nrr=0;
    nl=robbing(root->left,nll,nlr);
    nr=robbing(root->right,nrl,nrr);
    return max(root->val+nll+nlr+nrl+nrr,nl+nr);
   }

    int rob(TreeNode* root) {
        int ans=0;
        int nl=0,nr=0;
        ans=robbing(root,nl,nr);
        return ans;
    }
};