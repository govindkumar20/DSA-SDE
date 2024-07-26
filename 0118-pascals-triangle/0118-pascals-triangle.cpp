class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<n;i++){
            ans.push_back(vector<int> (i+1,1));
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
            
        }
        return ans;
    }
};