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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL )
        {
            return ans;
        }
        queue<TreeNode*> q;
        bool lefttoright=true;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> level(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                int index=(lefttoright)?i:n-i-1;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level[index]=node->val;

            }
            ans.push_back(level);
            lefttoright=!lefttoright;
        }
        return ans;
    }
};