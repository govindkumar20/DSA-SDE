class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        dp[0][0]=1;
        for(int i=0;i<m && p[i]=='*';i++) dp[0][i+1]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                } else if(p[j-1]=='*'){
                 dp[i][j]=dp[i-1][j]||dp[i][j-1];                    
                }
            }
        }
        return dp[n][m];
    }
};