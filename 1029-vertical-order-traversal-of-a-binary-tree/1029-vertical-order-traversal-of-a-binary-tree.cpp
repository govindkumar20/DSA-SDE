
class Solution {
public:
    vector<vector<int>> ans;
    void traverse(TreeNode* root, int x, int y, map<int,vector<pair<int,int>>>& m){
        if(root== NULL) return;
        m[y].push_back({x,root->val});
        traverse(root->left,x+1,y-1,m);
        traverse(root->right,x+1,y+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        traverse(root,0,0,m);
        for(auto i:m){
            sort(i.second.begin(),i.second.end());
            vector<int> temp;
            for(auto it:i.second) temp.push_back(it.second);
            ans.push_back(temp);
        }
        return ans;
    }
};