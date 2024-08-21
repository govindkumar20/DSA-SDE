class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>> adj,vector<vector<int>>& isConnected){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]) {
                
                dfs(i,vis,adj,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
         
        //making adj list
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        //visited array
        vector<int> vis(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,isConnected);
                provinces++;

            }
        }
        return provinces;
    }
};