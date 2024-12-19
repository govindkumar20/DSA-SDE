class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++) q.push({nums[i],i}); 
        while(k--){
            int temp1=q.top().first;
            int temp2=q.top().second;
            q.pop();
            q.push({temp1*multiplier,temp2});
        }
        vector<int> ans(n);
        while(!q.empty()){
            ans[q.top().second]=q.top().first;
            q.pop();
        }
        return ans;
    }
};