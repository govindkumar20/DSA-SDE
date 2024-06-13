class Solution {
public:
    int findMaxForm(vector<string>& s, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto c:s){
            int zeroes=count(c.begin(),c.end(),'0');
            int ones=c.size()-zeroes;
            
            for(int i=m;i>=zeroes;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-zeroes][j-ones]);
                }
            }
            
        }
        return dp[m][n];
    }
};