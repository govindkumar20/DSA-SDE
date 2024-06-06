class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<int ,int> m;
        for(auto i:s) m[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i:m)
        {
            pq.push({i.second,i.first});
            
        }
        string ans="";
        while(!pq.empty())
        {
            int temp=pq.top().first;
            while(temp--)
            {
                ans+=pq.top().second;
            }
            pq.pop();
        }
       // reverse(ans.begin(),ans.end());
        return ans;
    

    }
};