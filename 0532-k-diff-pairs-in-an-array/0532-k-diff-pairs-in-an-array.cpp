class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // main crux nums[j]=nums[i]+k
        map<int,int> m;
        for(auto i:nums) m[i]++;
        int ans=0;
        for(auto i:m)
        {
            if(k==0)    //if k=0. freq must be grtr than 1 
            {
               if(i.second>1) ans++;
            } else if(m.find(i.first+k)!=m.end())
            {
                ans++;
            }
        }
        return ans;
    }
};