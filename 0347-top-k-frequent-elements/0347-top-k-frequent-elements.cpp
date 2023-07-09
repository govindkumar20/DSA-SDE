class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;   //first=element second==count
        }
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto [a,b]:m)
        {
            pq.push({b,a});   //b is freq bcz root nneds to have max frequency
        }
        while(k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};