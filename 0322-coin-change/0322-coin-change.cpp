class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int m=amount;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=1;j<=m;j++) dp[0][j]=INT_MAX-1; // infinite no of coins are required  eg:-4/3
        // for(int j=1;j<=m;j++){
        //     if(j%coins[0]==0) dp[1][j]=j/coins[0];
        //     else dp[1][j]=INT_MAX-1;
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]); //+1 bcz if we consider a coint increment coins by one
                } else{
                    dp[i][j]=dp[i-1][j];
                }


            }

        }
        return dp[n][m]==INT_MAX-1?-1:dp[n][m];
    }
};