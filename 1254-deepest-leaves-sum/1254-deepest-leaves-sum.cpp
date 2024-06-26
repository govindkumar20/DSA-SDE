
class Solution {
public:
queue<TreeNode*> q;
vector<vector<int>> v;
    int deepestLeavesSum(TreeNode* root) {
        //simple level order traversal and return the sum of nodes belonging to last level
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
            }
            v.push_back(level);
        }
        int sum=0;
        vector<int> temp=v.back();
        cout<<v.size();
        for(auto i:temp) sum+=i;
        return sum;
    }
};