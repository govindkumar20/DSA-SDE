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
     vector<int> v;
     //TreeNode* new_root=NULL;
     vector<int> inorder(TreeNode* root){
        if(root==NULL) return v;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return v;
     }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        //for(auto i:v) cout<<i<<" ";
        int n=v.size();
        TreeNode* new_root=new TreeNode(v[0]);
        TreeNode* curr=new_root;
        for(int i=1;i<n;i++){
         curr->right= new TreeNode(v[i]);
         curr=curr->right;

        }
        
        return new_root;
    }
};