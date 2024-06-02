class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int l=0,r=0;
        int sum=0;
        int length=INT_MAX;
        while(r<n)
        {
            sum+=nums[r++];
            while(sum>=target)
            {
                length=min(length,r-l);
                sum-=nums[l++];
            }
        }
        return  length==INT_MAX?0:length;
    }
};