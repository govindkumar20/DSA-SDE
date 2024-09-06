class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& grid,int empty,int i, int j, int er,int ec){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]<0) return;
        if(i==er && j==ec) {
            if(empty==0) ans++;
            return;
        }
        grid[i][j]=-2;
        dfs(grid,empty-1,i-1,j,er,ec);
        dfs(grid,empty-1,i+1,j,er,ec);
        dfs(grid,empty-1,i,j-1,er,ec);
        dfs(grid,empty-1,i,j+1,er,ec);
        grid[i][j]=0;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sr,sc,er,ec;
        int empty=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) empty++;
                else if(grid[i][j]==1) sr=i,sc=j;
                else if(grid[i][j]==2) er=i, ec=j;
            }
        }
        dfs(grid,empty,sr,sc,er,ec);
        return ans;
    }
};