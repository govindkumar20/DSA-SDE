class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int ans=0;
        int maxSoFar=0;
        for(auto i:events){
            int start=i[0]; int end=i[1]; int val=i[2];
            while(!q.empty() && q.top().first<start){
                maxSoFar=max(maxSoFar,q.top().second);
                q.pop();
            }
            ans=max(ans,maxSoFar+val);
            q.push({end,val});

        }
        return ans;
    }
};