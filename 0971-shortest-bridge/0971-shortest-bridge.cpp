class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    void dfs( int i, int j,vector<vector<int>>& grid, queue<pair<int,int>>& q){   //basic dfs
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]==-1 || grid[i][j]==0) return;
        grid[i][j]=-1;
        q.push({i,j});
        dfs(i-1,j,grid,q);
        dfs(i+1,j,grid,q);
        dfs(i,j-1,grid,q);
        dfs(i,j+1,grid,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,q);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        int ans=0;
        //multi-source bfs to find the shortedt distance b/w 1st and 2nd island
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+xm[i];
                int nc=c+ym[i];
                if(nr>=0 && nc>=0 && nr<=n-1 && nc<=m-1 && grid[nr][nc]!=-1){
                    if(grid[nr][nc]==1) return ans;
                   if(grid[nr][nc]==0){
                    grid[nr][nc]=-1;
                    q.push({nr,nc});
                   } 
                }
            }
            }
            ans++;
        }
     return -1;
     }
};