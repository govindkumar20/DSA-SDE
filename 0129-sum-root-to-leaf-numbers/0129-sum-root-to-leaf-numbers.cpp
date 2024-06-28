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
    //int s=0;

    void dfs(TreeNode* root,string& l,int &s){
    if(root==NULL) return;
    l+=to_string(root->val);
    if(root->left==NULL && root->right==NULL){
         s+=stoi(l);
    }
    dfs(root->left,l,s);
    dfs(root->right,l,s);
    l.erase(l.size()-1);// backtrack
    }

    int sumNumbers(TreeNode* root) {
        int s=0;
        string l="";
        dfs(root,l,s);
        return s;
    }
};