class Solution {
public:
    int numSquares(int m) {
        vector<int> v;
        for(int i=1;i<=m;i++){
            if((i*i)<=m) v.push_back(i*i);
        }
        int n=v.size();
       vector<vector<int>> dp(n+1,vector<int>(m+1));
       for(int i=0;i<=n;i++) dp[i][0]=0;
       for(int j=1;j<=m;j++) dp[0][j]=INT_MAX-1;
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i-1]<=j){
                dp[i][j]=min(dp[i][j-v[i-1]]+1, dp[i-1][j]);
            } else{
                dp[i][j]=dp[i-1][j];
            }
        }
       }
       return dp[n][m];
    }
};