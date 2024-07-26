class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis, int i, int j){ // basic dfs on a grid
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || grid[i][j]==0) return 0;
        vis[i][j]=1;
        return 1+dfs(grid,vis,i-1,j)+dfs(grid,vis,i,j+1)+dfs(grid,vis,i+1,j)+dfs(grid,vis,i,j-1);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n=grid.size();
        int m=grid[0].size();
        int maxarea=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area=dfs(grid,vis,i,j);
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};