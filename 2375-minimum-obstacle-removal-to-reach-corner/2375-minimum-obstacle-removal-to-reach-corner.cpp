class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n+1,vector<int>(m+1,1e9));
        dist[0][0]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+xm[i];
                int nc=c+ym[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(grid[r][c]+dist[r][c]<dist[nr][nc]){
                        dist[nr][nc]=grid[r][c]+dist[r][c];
                        q.push({nr,nc});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};