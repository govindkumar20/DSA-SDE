class Solution {
public:
// elements inside stack are s2
//smaller elements than s2 are candidates for s1
// if s3>s1 implies s1<s2
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        int cur_min=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<cur_min) return true;
            else while(!s.empty() && nums[i]>s.top())
            {
                cur_min=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};