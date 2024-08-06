
class Solution {
public:
   
    vector<TreeNode*> levelOrder(TreeNode* root){ 
        vector<TreeNode*> lvl;
        if(root==NULL) return lvl;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            lvl.clear();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                lvl.push_back(node);
            }  
        }
        return lvl;
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return 0;
        if(root==p || root==q) return root;
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left && right) return root;
        else if(left) return left;
        else return right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> level=levelOrder(root);
        if(level.size()==1) return lca(root,level[0],NULL);
        else return lca(root,level[0],level[level.size()-1]);
    }
};