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
    int ans=0;
    void dfs(TreeNode* root,int dr,int steps){
        if(root==NULL) return;
        ans=max(ans,steps);
        if(dr==0) {
            dfs(root->right,1,steps+1); //follow zig-zag path i.e next node in opp. drn
            dfs(root->left,0,1);   // or start a new path from curr node in same drn
        } else{
            dfs(root->left,0,steps+1);
            dfs(root->right,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root->left,0,1);
        dfs(root->right,1,1);
        return ans;
    }
};