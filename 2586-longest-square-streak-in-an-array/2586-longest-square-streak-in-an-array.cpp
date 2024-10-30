class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int,int> m;
        sort(nums.begin(),nums.end());
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int _sq=sqrt(nums[i]);
            if(_sq*_sq==nums[i] && m.find(_sq)!=m.end()){
                m[nums[i]]=m[_sq]+1;
                ans=max(ans,m[nums[i]]);
            } else{
                m[nums[i]]=1;
            }
        }
        return ans;
    }
};

/*
2 3 4 6 8 16
ans=0
map={2,2}
    {3,1}
    {6,1}
    {8,1}
    {}


*/