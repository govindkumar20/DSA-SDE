class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;
        for(auto i:nums) totalSum+=i;
        if(target>totalSum || (target+totalSum)%2!=0) return 0;
        int s=(target+totalSum)/2;
        if(s<0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(s+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s];
    }
};