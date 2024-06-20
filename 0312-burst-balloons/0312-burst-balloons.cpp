class Solution {
public:
      int solve(vector<int> & a,vector<vector<int>> & dp, int i, int j){
        if(i>j) return 0;
        int ans=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++){
        int  temp_ans=(a[i-1]*a[k]*a[j+1])+solve(a,dp,i,k-1)+solve(a,dp,k+1,j);
            ans=max(ans,temp_ans);
        }
        return dp[i][j]=ans;
      }

    int maxCoins(vector<int>& nums) {
        vector<int> v;
        v.push_back(1);
        for(auto i:nums) v.push_back(i);
        v.push_back(1);
        int n=v.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(v,dp,1,n-2);
    }
};