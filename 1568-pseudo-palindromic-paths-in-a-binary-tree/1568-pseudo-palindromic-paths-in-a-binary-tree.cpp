
class Solution {
public:
    int count=0;
    void dfs(TreeNode* root,vector<int> temp){
        if(root==NULL) return;
        if(root->left || root->right) {
            temp[root->val]++;
        } else{
            temp[root->val]++;
            int flag=0;
            for(int i=0;i<=9;i++){
                if(temp[i]%2!=0) flag++;
            }
            if(flag==0 || flag<=1) count++; 
        }
        dfs(root->left,temp);
        dfs(root->right,temp);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10,0);
        dfs(root,temp);
        return count;
        
    }
};