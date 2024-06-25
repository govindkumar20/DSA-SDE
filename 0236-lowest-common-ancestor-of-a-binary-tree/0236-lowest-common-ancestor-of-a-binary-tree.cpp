
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;//if leaf node or not found return null
        if(root->val==p->val || root->val==q->val) return root; // if any of them fount return it
       TreeNode* left= lowestCommonAncestor(root->left,p,q);// recursion
       TreeNode*  right= lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;  // if both found
        else if(left) return left; // if(both lies in same path)
        else return right;
    }
};