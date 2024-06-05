class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int sum_ind=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            sum_ind+=i*nums[i];
        }
        int ans=sum_ind;
        for(int i=n-1;i>=0;i--)
        {
            sum_ind+=sum-n*nums[i];
            ans=max(ans,sum_ind);
        }
        return ans;
    }
};