
class Solution {
public:
   void traverse(TreeNode* root, int level, int dist,map<int,vector<pair<int,int>>>& m){
    if(root==NULL) return;
    m[dist].push_back({level,root->val});
    traverse(root->left,level+1,dist-1,m);
    traverse(root->right,level+1,dist+1,m);
   }
   vector<vector<int>> ans;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        traverse(root,0,0,m);
        for(auto it:m){
            sort(it.second.begin(),it.second.end());
            vector<int> temp;
            for(auto i:it.second) temp.push_back(i.second);
            ans.push_back(temp);
        }
        return ans;
    }
};