class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>& vis, bool& isSub){
        int n=grid1.size();
        int m=grid1[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid2[i][j]==0 || vis[i][j]==1) return;
        vis[i][j]=1;
        if(grid1[i][j]==0) isSub=false;
        dfs(i-1,j,grid1,grid2,vis,isSub);
        dfs(i+1,j,grid1,grid2,vis,isSub);
        dfs(i,j-1,grid1,grid2,vis,isSub);
        dfs(i,j+1,grid1,grid2,vis,isSub);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
    
        int count=0;
        bool isSub=true;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && vis[i][j]==0){
                    isSub=true;
                    dfs(i,j,grid1,grid2,vis,isSub);
                    if(isSub) count++;
                }
            }
        }
        return count;
    }
};