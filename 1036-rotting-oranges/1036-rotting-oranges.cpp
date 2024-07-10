class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        vector<vector<int>> vis(n,vector<int>(m));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                } else {
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) fresh++;
             }
        }

        vector<int> xm={-1,0,1,0};
        vector<int> ym={0,1,0,-1};

        int time=0;
        int count=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            time=max(time,q.front().second);
            q.pop();
        
        for(int i=0;i<4;i++){
            int nrow=r+xm[i];
            int ncol=c+ym[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, time+1});
                    count++;
                }
        }
        }
        if(fresh!=count) return -1;
        return time;
    }
};