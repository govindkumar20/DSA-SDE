class Solution {
public:
void dfs(int n, int node, vector<vector<int>>& adj,vector<vector<int>>& connections,vector<int>& vis ){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(n,i,adj,connections,vis);
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
         vector<int> vis(n,0);
         int count=0;
        for(int i=0;i<n;i++){
         if(!vis[i]){
            dfs(n,i,adj,connections,vis);
            count++;
         }
        }
        return count-1;
    }
};