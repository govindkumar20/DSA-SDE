class Solution {
public:
     vector<int> xm={-1,0,1,0};
     vector<int> ym={0,1,0,-1};
     void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>> grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>n-1 || j<0 || j>m-1 || vis[i][j] || grid[i][j]==0 ) return;
        vis[i][j]=1;
        for(int p=0;p<4;p++){
            dfs(i+xm[p],j+ym[p],vis,grid);
        }

     }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]) dfs(0,j,vis,grid);
            if(grid[n-1][j]==1 && !vis[n-1][j]) dfs(n-1,j,vis,grid);
        }
        for(int i=1;i<n-1;i++){
            if(grid[i][0]==1 && !vis[i][0]) dfs(i,0,vis,grid);
            if(grid[i][m-1]==1 && !vis[i][m-1]) dfs(i,m-1,vis,grid);
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) count++;
            }
        }
        return count;
    }
};