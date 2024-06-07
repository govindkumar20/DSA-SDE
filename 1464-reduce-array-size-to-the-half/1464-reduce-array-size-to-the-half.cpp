class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto i:arr) m[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i:m) pq.push({i.second,i.first});
        int ans=0;
        int removed=0;
        while(removed<arr.size()/2)
        {
            removed+=pq.top().first;
            pq.pop();
            ans++;

        }
        return ans;
    }
};