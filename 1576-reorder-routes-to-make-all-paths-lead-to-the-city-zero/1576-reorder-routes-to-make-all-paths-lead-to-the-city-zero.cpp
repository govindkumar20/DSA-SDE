class Solution {
public:
   int dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
    int ans=0;
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[abs(i)]){
            ans+=dfs(abs(i),adj,vis)+(i>0); // agr i +ve hai mtlb opp drn w.r.t source , so ans+1
        }
    }
    return ans;
   }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        // first treat draph as undirected
        for(auto i:connections){
            adj[i[0]].push_back(i[1]); //  edges going away from node
            adj[i[1]].push_back(-i[0]);  //edges towards source
        } 
        vector<int> vis(n,0);
        return dfs(0,adj,vis);
    }
};