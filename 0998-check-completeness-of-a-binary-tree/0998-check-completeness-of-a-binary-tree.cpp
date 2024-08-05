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
    bool isCompleteTree(TreeNode* root) {
        // intution: in a complete BT after first null node  there will be no non null node 
        // the size of queue will be null after traversal
       bool flag=0;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) flag=1;
            else{
                if(flag) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
       }
       return true;
        
    }
};