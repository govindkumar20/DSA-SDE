class Solution {
public:
    int solve(vector<vector<int>>& dp, int i, int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
         int temp_ans=k+max(solve(dp,i,k-1),solve(dp,k+1,j));
         ans=min(ans,temp_ans);
        }
        return dp[i][j]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(dp,1,n);
    }
};