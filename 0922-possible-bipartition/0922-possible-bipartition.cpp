class Solution {
public:
    bool bfs(int node,vector<int>& vis, vector<vector<int>>& adj){
        queue<int> q;
        q.push(node);
        vis[node]=0;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(auto i:adj[val]){
                if(vis[i]==-1){
              vis[i]=!vis[val];
              q.push(i);
            } else{
                if(vis[i]==vis[val]) return false;
            }
         }
          
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

        }
        vector<int> vis(n+1,-1);
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                if(!bfs(i,vis,adj)) return false;
            }
        }
        return true;
    }
};