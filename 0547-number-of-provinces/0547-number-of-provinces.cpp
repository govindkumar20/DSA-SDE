class Solution {
 public:
     void dfs(vector<vector<int>>& matrix,vector<int>& vis,vector<vector<int>> adj,int node){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]) dfs(matrix,vis,adj,i);
        }
     }

    int findCircleNum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                count++;
                dfs(matrix,vis,adj,i);
            } 
        }

        return count;
    }
};