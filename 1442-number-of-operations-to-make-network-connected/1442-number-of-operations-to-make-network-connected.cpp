class Solution {
public:

    void dfs(int i,vector<vector<int>>& adj, vector<int>& vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto i:connections){
           adj[i[0]].push_back(i[1]);
           adj[i[1]].push_back(i[0]);

        }
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count-1;
    }
};