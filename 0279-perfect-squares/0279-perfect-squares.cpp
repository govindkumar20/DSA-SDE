class Solution {
public:
    int numSquares(int m) {
        vector<int> temp;
        for(int i=1;i<=m;i++){  // making parfect squares vector
            if(i*i<=m) temp.push_back(i*i);
        }
        //now coin change  steps
        int n=temp.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=INT_MAX-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(temp[i-1]<=j) dp[i][j]=min(1+dp[i][j-temp[i-1]],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][m]==INT_MAX-1?-1:dp[n][m];
        
    }
};