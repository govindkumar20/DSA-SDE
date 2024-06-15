class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //s+s=2s
        // so find whether there exist a subset with sum=sum/2
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%2!=0) return false;
        int m=sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int j=1;j<=m;j++) dp[0][j]=false;
        // filling up of dp table
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
       return dp[n][m];
    }
};