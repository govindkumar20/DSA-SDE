class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;int r=0;
        int zeroes=0;
        int ans=0;
        while(r!=n)
        {
            if(nums[r]==0)
            {
                zeroes++;
            }
            if(zeroes>k)
            {
                if(nums[l]==0) zeroes--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};