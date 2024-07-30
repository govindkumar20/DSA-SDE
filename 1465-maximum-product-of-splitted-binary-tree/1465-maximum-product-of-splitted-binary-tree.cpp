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

    vector<int> sums;
    int FindSum(TreeNode* root){
        if(root==NULL) return 0;
        int left= FindSum(root->left);
        int right= FindSum(root->right);
        int sum= root->val+left+right;
        sums.push_back(sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        long long ans=0;
        long long sum=FindSum(root);
        for(auto i:sums){
            ans=max(ans,i*(sum-i));
        }
        return ans%1000000007;
    }
};