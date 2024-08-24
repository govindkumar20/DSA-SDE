class Solution {
public:
    bool bfs(int node,vector<int>& vis,vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        vis[node]=0;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(auto i:graph[val]){
                if(vis[i]==-1){
                    vis[i]=!vis[val];
                    q.push(i);
                } else if(vis[i]==vis[val]){
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);

        for(int i=0;i<n;i++){
           if(vis[i]==-1){
            if(!bfs(i,vis,graph)) return false;
           }
        }
        return true;
    }
};