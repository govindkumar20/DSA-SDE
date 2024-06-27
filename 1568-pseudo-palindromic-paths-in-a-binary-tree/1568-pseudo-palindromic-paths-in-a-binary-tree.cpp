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
    void solve(TreeNode* root,vector<int> & ans,int & count){
        if(root==NULL) return;
        ans[root->val]++;
        solve(root->left,ans,count);
        solve(root->right,ans,count);
        
        if(root->left==NULL && root->right==NULL) {
            int flag=0;
            for(int i=0;i<=9 ;i++){
                if(ans[i]%2!=0)flag++;
            }
                if(flag==0 || flag==1) count++; 
        }  
        ans[root->val]--;
    }




    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int> ans(10,0);
        solve(root,ans,count);
        return count;
    }
};