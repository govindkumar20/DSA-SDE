class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //unbounded knapsack
        int n=coins.size();
        int m=amount;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){ //filling up of dp matrix
            for(int j=1;j<=m;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i][j-coins[i-1]]+ dp[i-1][j];
                } else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};