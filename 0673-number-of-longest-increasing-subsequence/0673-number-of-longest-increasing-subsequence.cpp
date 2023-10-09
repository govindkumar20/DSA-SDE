class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;

        vector<int> length(nums.size(),1);
        vector<int> count(nums.size(),1);

        int maxi=1;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && length[j]+1>length[i])
                {
                length[i]=length[j]+1;
                count[i]=count[j];
                } 
                else if(nums[j]<nums[i] && length[j]+1==length[i])
                {
                 count[i]+=count[j];
                }
            }
            maxi=max(maxi,length[i]);

        }
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            if(length[i]==maxi) result+=count[i];
        }
        return result;
    }
};