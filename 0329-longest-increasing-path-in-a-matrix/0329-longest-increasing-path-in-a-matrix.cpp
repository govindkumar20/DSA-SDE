class Solution {
public:
 // dp memoization + dfs
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};

    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix, int prev){
          int n=matrix.size();
        int m=matrix[0].size();
        if(i<0 || j<0 || i>=n || j>=m || prev>=matrix[i][j]) return 0;

        if(dp[i][j]!=-1) return dp[i][j]; 
        int best=0;
        for(int p=0;p<4;p++){
            int curr=dfs(i+xm[p],j+ym[p],dp,matrix,matrix[i][j]);
            best=max(best,curr);
        }
       return dp[i][j]=best+1;
    }

   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,dfs(i,j,dp,matrix,-1));
            }
        }
        return maxi;
    }
};