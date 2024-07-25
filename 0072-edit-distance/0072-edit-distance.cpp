class Solution {
public:
    int minDistance(string text1, string text2) {
          int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i; // deleting all char 
        for(int j=0;j<=m;j++) dp[0][j]=j;  //inserting all char
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
            }
        }
        cout<<dp[n][m];
        return dp[n][m];
        
    }
};