class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        // for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        // for(int i=0;i<n;i++) dp[i][0]=matrix[i][0];
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    if (matrix[i][j] == '1')
                        dp[i][j] = 1;
                } else {
                    if(matrix[i][j]=='1')
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1]));
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};