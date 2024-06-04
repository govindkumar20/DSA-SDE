class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int n=nums.size();
       set<int> s;
       for(auto i:nums)
       {
        if(!s.insert(i).second) s.erase(i);
        else s.insert(i);
       }
       return vector<int> (s.begin(),s.end());
    }
};