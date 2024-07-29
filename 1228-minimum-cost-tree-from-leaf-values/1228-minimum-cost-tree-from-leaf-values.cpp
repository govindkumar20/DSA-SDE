class Solution {
public:
    int solve(vector<int>& arr, vector<vector<int>>& dp, int i, int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int sum=solve(arr,dp,i,k)+solve(arr, dp,k+1,j);
            int a=*max_element(arr.begin()+i,arr.begin()+k+1);
            int b=*max_element(arr.begin()+k+1,arr.begin()+j+1);
             ans=min(ans,sum+a*b);

        }
        return dp[i][j]=ans;
    }

 
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,dp,0,n-1);
    }
};