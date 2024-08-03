
class Solution {
public:
   
    void dfs(TreeNode* root,int curr_sum,int& totalSum,string temp){
        if(root==NULL) return;
        if(root->left || root->right){
             temp+=to_string(root->val);
        }
        else {
            temp+=to_string(root->val);
            totalSum+=stoi(temp);
        }
        dfs(root->left,curr_sum,totalSum,temp);
        dfs(root->right,curr_sum,totalSum,temp);
    }


    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        int curr_sum=0;
        string temp="";
        dfs(root,curr_sum,totalSum,temp);
        return totalSum;
    }
};