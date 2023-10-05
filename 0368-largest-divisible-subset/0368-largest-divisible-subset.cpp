class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if(nums.size()==0) return result;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>());

        for(int i=0;i<n;i++)
        {
            vector<int> maxsubset;
            for(int j=0;j<i;j++)
            {
               if(nums[i]%nums[j]==0 && maxsubset.size()<dp[j].size())
               {
                   maxsubset=dp[j];
               }
            }
            dp[i]=maxsubset;
            dp[i].push_back(nums[i]);

        }

        for(int i=0;i<n;i++)
        {
            if(result.size()<dp[i].size())
            {
                result=dp[i];
            }
        }
        return result;
    }
};