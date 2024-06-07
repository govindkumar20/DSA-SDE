class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
           double dist=static_cast<double>(pow((points[i][0]*points[i][0])+(points[i][1]*points[i][1]),0.5));
           pq.push({dist,{points[i][0],points[i][1]}});
        }
        while(pq.size()!=k)
        {
            pq.pop();
        }
        vector<vector<int>> v;
        while(!pq.empty()){
            v.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
     return v;
    }
};