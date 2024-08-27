class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; //{time,node}
        dist[k]=0;
        q.push({0,k});
        while(!q.empty()){
            int node=q.top().second;
            int time=q.top().first;
            q.pop();
            for(auto i:adj[node]){
                int adjNode=i.first;
                int edgW=i.second;
                if(edgW+time<dist[adjNode]){
                    dist[adjNode]=edgW+time;
                    q.push({time+1,adjNode});
                }
            }
        }
        int minTime=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            minTime=max(minTime,dist[i]);

        }
        return minTime;


    }
};