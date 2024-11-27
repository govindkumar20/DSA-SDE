class Solution {
public:
    int dijkstra(int n, vector<vector<int>>& adj){
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        dist[0]=0;
        while(!q.empty()){
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            for(auto i:adj[node]){
                if(d+1<dist[i]){
                    dist[i]=d+1;
                    q.push({dist[i],i});
                }
            }
        }
        return dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
           // adj[i+1].push_back(i);
        }
        vector<int> ans;
        int size=queries.size();
        for(auto i:queries){
            adj[i[0]].push_back(i[1]);
           // adj[i[1]].push_back(i[0]);
            int temp=dijkstra(n,adj);
            ans.push_back(temp);

        }
        return ans;
    }
};