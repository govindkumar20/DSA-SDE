class Solution {
public:
    int integerBreak(int n) {
        if(n==3) return 2;
        else if(n<=2) return 1;
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=n;j++) dp[0][j]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(v[i-1]<=j){
                    dp[i][j]=max(v[i-1]*dp[i][j-v[i-1]], dp[i-1][j]);
                } else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
};