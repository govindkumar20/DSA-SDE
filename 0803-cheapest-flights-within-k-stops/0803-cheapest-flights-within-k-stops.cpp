class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){  //adj list
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q; // {stops,{node,cost}}
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
           int  stops=q.front().first;
           int node=q.front().second.first;
           int cost=q.front().second.second;
         q.pop();
           for(auto itr:adj[node]){
            int edjW=itr.second;
            int adjnode=itr.first;
            if(cost+edjW<dist[adjnode] && stops<=k){
                dist[adjnode]=cost+edjW;
                q.push({stops+1,{adjnode,cost+edjW}});
            }
           }

        }
       return dist[dst]==1e9?-1:dist[dst];
    }
};