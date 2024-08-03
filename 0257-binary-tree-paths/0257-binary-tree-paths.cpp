
class Solution {
public:
    void dfs(TreeNode* root,vector<string>& ans, string cur){
        if(root==NULL) return ;
        if(root->left || root->right){
            cur+=to_string(root->val)+"->";

        } else{
            cur+=to_string(root->val);
            ans.push_back(cur);
        }
        dfs(root->left,ans,cur);
        dfs(root->right,ans,cur);
    }



    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string cur="";
        dfs(root,ans, cur);
        return ans;
    }
};