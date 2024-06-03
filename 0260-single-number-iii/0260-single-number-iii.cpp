class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
       map<int,int> m;
       for(auto i:nums)
       {
        m[i]++;
       }
       vector<int> ans;
      for(auto i:m)
      {
        if(i.second==1)
        {
            ans.push_back(i.first);
        }
      }
      return ans;
    }
};