
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int n=q.size();
            count++;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(count==depth-1){
                TreeNode* temp1=new TreeNode(val);
                temp1->left=node->left;
                node->left=temp1;
                 
                TreeNode* temp2=new TreeNode(val);
                temp2->right=node->right;
                node->right=temp2;

            } else{
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            }
        }
        return root;
    }
};