class Solution {
public:
int timer=1;
    void dfs(int node,int parent, vector<int>& vis, int tin[], int low[], vector<vector<int>> & bridges, vector<vector<int>>& adj){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto i:adj[node]){
            if(i==parent) continue;
            if(vis[i]==0){
               dfs(i,node,vis,tin,low,bridges,adj);
               low[node]=min(low[node],low[i]);
               // if thats a bridge or not
               if(low[i]>tin[node]) bridges.push_back({i,node});
            } else {
               low[node]=min(low[node],low[i]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vis,tin,low,bridges,adj);
        return bridges;
    }
};