class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
      map<long,long> m;
      long prefix_xor=0;
      long ans=0;
      m[0]=1;
      for(auto i:nums)
      {
        prefix_xor^=i;
        ans+=m[prefix_xor];
        m[prefix_xor]++;
        
      }  
     return ans;
    }
};