class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<vector<int>>& adj,vector<int>& vis,int node){  // basic dfs
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(rooms,adj,vis,i);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>> adj(n);  // adjacency list
        for(int i=0;i<n;i++){
            adj[i]=rooms[i];
        }
         vector<int> vis(n,0);

         int start=0;
         dfs(rooms,adj,vis,start);
         for(int i=0;i<n;i++){  // if all nodes visited return true else false even if a single node is unvisited
            if(vis[i]==0){
                return false;
            }
         }
     return true;

    }
};