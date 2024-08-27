class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q; // stops,{node,cost}
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int node=q.front().second.first;
            int cost=q.front().second.second;
            int steps=q.front().first;
            q.pop();
            for(auto i:adj[node]){
                int adjNode=i.first;
                int edgW=i.second;
                if(cost+edgW<dist[adjNode] && steps<=k){
                    dist[adjNode]=cost+edgW;
                    q.push({steps+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];


    }
};