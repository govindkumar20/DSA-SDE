class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<uint> dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(auto c:nums)
            {
                if(c<=i)
                {
                    dp[i]+=dp[i-c];
                }
            }
        }
        return dp[target];
    }
};