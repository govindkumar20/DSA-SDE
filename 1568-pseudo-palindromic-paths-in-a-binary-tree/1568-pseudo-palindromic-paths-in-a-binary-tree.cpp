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
        ans[root->val]++; //inr the corresponding index value
        solve(root->left,ans,count);
        solve(root->right,ans,count);
        
        if(root->left==NULL && root->right==NULL) {  // when we reached leaf node ie one path is completed
            int flag=0;
            for(int i=0;i<=9 ;i++){
                if(ans[i]%2!=0)flag++; // if no of nodes with odd occurences greater than 1 then no permutation can form palindrome
            }
                if(flag==0 || flag==1) count++; 
        }  
        ans[root->val]--;// as we backtrack dcr the incremented indices values for further cal of more paths
    }




    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int> ans(10,0);  // vector containing indices of values from 1-9 
        solve(root,ans,count);
        return count;
    }
};