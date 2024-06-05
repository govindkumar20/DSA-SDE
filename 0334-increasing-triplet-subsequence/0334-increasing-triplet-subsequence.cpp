class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      
        int s1=INT_MAX;
        int s2=INT_MAX;
        for(auto i:nums)
        {
            if(i<=s1)s1=i;
            else if(i<=s2) s2=i;
            else return true;
        }
        return false;
    }
};