class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        vector<int> steps(n,0);
        stack<int> s;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]>nums[s.top()]){
                steps[i]=max(steps[i]+1,steps[s.top()]);
                 ans=max(ans,steps[i]);
                s.pop();
            }
            s.push(i);
           
        }
        return ans;
    }
};