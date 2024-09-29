
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int maxLevel=1;
        int maxSum=INT_MIN;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum+=node->val;
            }
           if(sum>maxSum){
            maxSum=sum;
            maxLevel=level;
           }
           level++;
        }
        return maxLevel;
    }
};