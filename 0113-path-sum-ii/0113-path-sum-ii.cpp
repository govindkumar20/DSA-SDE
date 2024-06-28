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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
     vector<int> v;
     vector<vector<int>> ans;
     dfs(root,targetSum,ans,v);
     return ans;
    }
    void dfs(TreeNode* root,int targetSum,vector<vector<int>>& ans, vector<int>& v){
       if(root==NULL) return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            int sum=0;
            for(auto i:v) sum+=i;
            if(sum==targetSum){
                ans.push_back(v);
            }
         
        }
        dfs(root->left,targetSum,ans,v);
        dfs(root->right,targetSum,ans,v);
        v.pop_back();
       //for(auto i:v) cout<<i<<" ";

       
    }
};