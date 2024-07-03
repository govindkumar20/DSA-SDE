
class Solution {
public:
    vector<string> v;
    string s="";
    void dfs(TreeNode* root){ 
        if(root==NULL) return;
        string prev=s;// save curr state of s for backtracking
        if(root->left || root->right){
            s+=to_string(root->val);
            s+="->";
        } else{
            s+=to_string(root->val);
            v.push_back(s);
           
        }
        dfs(root->left);
        dfs(root->right);
        s=prev;// backtracking (s to its prev state for new paths)
  
   
    }

    vector<string> binaryTreePaths(TreeNode* root) {
      dfs(root);
      return v;  
    }
};