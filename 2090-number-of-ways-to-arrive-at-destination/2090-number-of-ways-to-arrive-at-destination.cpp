class Solution {
public:
typedef long long int;
    int countPaths(int n, vector<vector<int>>& roads) {
         int mod = (1e9+7);
        vector<pair<int,int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});   
            adj[it[1]].push_back({it[0], it[2]});   // bcz of bidirectional edges
        }
       // for(auto i:roads) adj[i[0]].push_back({i[1],i[2]});
        vector<long long int> dist(n,1e18);
        vector<long long int> ways(n,0);
        priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,greater<pair<long long ,long long>>> q; //{time,node}
        q.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!q.empty()){
            long long time=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                long long edgW=it.second;
                if(time+edgW<dist[adjnode]){
                    dist[adjnode]=time+edgW;
                    ways[adjnode]=ways[node];
                    q.push({time+edgW,adjnode});
                } else if(time+edgW==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
               
            }
        }
        return ways[n-1]%mod;
    }
};