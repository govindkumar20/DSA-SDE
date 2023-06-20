class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int infpt=0;
        for(int i=n-1;i>0;i--)    //find inflation point
        {
            if(nums[i]>nums[i-1])
            {
                infpt=i;
                break;
            }
        }
        if(infpt==0)     // if no inflation point meansno next permutation
        {
            sort(nums.begin(),nums.end());
            return;
        }
       
       //if there exist inflation point
           
            for(int i=n-1;i>=0;i--)
            {
                if(nums[i]>nums[infpt-1])
                {
                    swap(nums[i],nums[infpt-1]);
                    sort(nums.begin()+infpt,nums.end());
                break;
                }
                
            }
        
        
    }
};