class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 ||i==n  || j==m || grid[i][j]=='0') { // boundary conditions
            return;
        }
        grid[i][j]='0';
        dfs(grid,i-1,j); // calls for neighbrours
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
   
    int numIslands(vector<vector<char>>& grid) {
        // traverse  grid and if value is 1 then inc count and make its neighbours 0 
      int n=grid.size();
      int m=grid[0].size();
      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         if(grid[i][j]=='1'){
            count++;
            dfs(grid,i,j); // dfs traversal
         }
        }
      }  
      return count;
    }
};