class Solution {
public:
 // mcm variant
    int solve(vector<int>& values,vector<vector<int>> & dp,int i, int j){
        if(i>=j) return 0; //  req range of  atleast length 2 
        if(dp[i][j]!=-1) return dp[i][j];
        int temp;
        int ans_min=INT_MAX;
        for(int k=i;k<j;k++){
            temp=solve(values,dp,i,k)+solve(values,dp,k+1,j)+values[i-1]*values[k]* values[j];
            ans_min=min(ans_min,temp);
        }
        return dp[i][j]=ans_min;

    }
   
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(values,dp,1,n-1);
    }
};