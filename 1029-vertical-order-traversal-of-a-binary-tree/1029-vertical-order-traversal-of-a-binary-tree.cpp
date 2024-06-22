
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //fucking good ques
        map<int,vector<int>> m;// <x-index values,vertical vectors>
        queue<pair<int,TreeNode*>> q; // for inorder traversal and put values acc to x-index
        q.push({0,root});
        while(!q.empty()){
            int n=q.size();
            multiset<pair<int,int>> s; // in order to handle more than 1 values at same pos
            for(int i=0;i<n;i++){
                auto node=q.front();   // other than these things very much similar to inorder traversal
                q.pop();
                s.insert({node.first,node.second->val});
                if(node.second->left) q.push({node.first-1,node.second->left});
                if(node.second->right) q.push({node.first+1,node.second->right});
            }
            for(auto i:s) m[i.first].push_back(i.second);
        }
        vector<vector<int>> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};