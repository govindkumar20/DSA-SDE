class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for( auto i: nums)
        {
            int curr=i;
            int prev=i-1;
            if(s.find(prev)==s.end())
            {
               int currlen=1;
               while(s.find(curr+1)!=s.end())
               {
                   currlen++;
                   curr++;
               }
               maxlen=max(maxlen,currlen);
            }
        }
        return maxlen;
    }
};