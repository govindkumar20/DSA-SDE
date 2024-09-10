class Solution {
public:
    bool isCycle=false;
    void dfs(int i, int j, vector<vector<char>>& grid,vector<vector<int>>& vis,int parent_x,int parent_y){
        int n=grid.size();
        int m=grid[0].size();
        if(vis[i][j]){
            isCycle=true;
            return;
        } 
        vis[i][j]=1;
        if(i+1<n && i+1!=parent_x &&  grid[i+1][j]==grid[i][j]) dfs(i+1,j,grid,vis,i,j);
        if(j+1<m && j+1!=parent_y &&  grid[i][j+1]==grid[i][j]) dfs(i,j+1,grid,vis,i,j);
        if(i-1>=0 && i-1!=parent_x &&  grid[i-1][j]==grid[i][j]) dfs(i-1,j,grid,vis,i,j);
        if(j-1>=0 && j-1!=parent_y &&  grid[i][j-1]==grid[i][j]) dfs(i,j-1,grid,vis,i,j);
       
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(!vis[i][j]){
                dfs(i,j,grid,vis,-1,-1);
            }
            }
        }
        return isCycle;
    }
};