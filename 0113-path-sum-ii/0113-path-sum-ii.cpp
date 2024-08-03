
class Solution {
public:
   void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int> cur, int targetSum,int curr_sum){
    if(root==NULL) return;
    if(root->left || root->right) {
        cur.push_back(root->val);
        curr_sum+=root->val;
    }
    else{
        cur.push_back(root->val);
        curr_sum+=root->val;
        if(targetSum==curr_sum){
            ans.push_back(cur);
        }

    }
    dfs(root->left,ans,cur,targetSum,curr_sum);
    dfs(root->right,ans,cur,targetSum,curr_sum);

   }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        int curr_sum=0;
        dfs(root,ans,cur,targetSum,curr_sum);
        return ans;
    }
};