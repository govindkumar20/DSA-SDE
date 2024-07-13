class Solution {
public: vector<int> xm={0,1,-1,0,1,-1,1,-1};
        vector<int> ym={1,0,0,-1,1,1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
         if(grid[0][0]==0 && n==1 && m==1){
            return 1;
        }
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        q.push({1,{0,0}});
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int i=0;i<8;i++){
                int nr=r+xm[i];
                int nc=c+ym[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0 && d+1<dist[nr][nc]){
                    dist[nr][nc]=1+d;
                    if(nr==n-1 && nc==m-1) return d+1;
                    q.push({1+d,{nr,nc}});

                }
            }
        }
      return -1;
    }
};