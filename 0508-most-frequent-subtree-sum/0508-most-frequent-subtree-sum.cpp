
class Solution {
public:
    vector<int> v;
    vector<int> ans;
    unordered_map<int,int> m;
    int dfs(TreeNode* root,int& sum){
        if(root==NULL) return 0;
        int left=dfs(root->left,sum);
        int right=dfs(root->right,sum);
        sum=root->val+left+right;
        m[sum]++;
        return sum;
    }

    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL) return ans;
        int sum=0;
        dfs(root,sum);
       
        int max_freq=0;
        for(auto i:m)  max_freq=max(max_freq,i.second);
        for(auto i:m){
            if(i.second==max_freq){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};