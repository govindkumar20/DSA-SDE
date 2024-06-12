class Solution {
public:

    bool solve(string s1, string s2, string s3, int i,int j,int k,vector<vector<int>> & dp){
        if(dp[i][j]!=-1) return dp[i][j];   // if dp[i][j] already calculated 
        if(i==s1.length() && j==s2.length() && k==s3.length()) return true; // if s3 is made from s1 and s2
        bool x=false;
        bool y=false;
        if(i!=s1.length()){
            if(s3[k]==s1[i]) {
                x=solve(s1,s2,s3,i+1,j,k+1,dp);
            }
        }
        if(j!=s2.length()){
            if(s3[k]==s2[j]){
                y=solve(s1,s2,s3,i,j+1,k+1,dp);
            }
        }
      return  dp[i][j]=x||y;

    }

    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); // momoization to avoid repeated calculation
        return solve(s1,s2,s3,0,0,0,dp);
    }
};