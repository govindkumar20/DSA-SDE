class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int diff=INT_MIN;
        int temp=INT_MIN;
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]!=diff)
            {
                diff=nums[i]-nums[i-1];
                temp=0;
            } else temp++; 
            if(temp>=1) {
                ans+=temp;
            }
        }
        return ans;
    }
};