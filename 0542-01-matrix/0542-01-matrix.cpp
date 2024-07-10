class Solution {
public: 
    vector<int> xm={-1,0,1,0}; // coordinates of 4 drn's
    vector<int> ym={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m)); // ans matrix
        vector<vector<int>> vis(n,vector<int>(m,0)); // visited matrix
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){  // insert all cells with 0 into q with steps as 0 and update visited mat
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                } else {
                    vis[i][j]=0;
                }
            }
        }

        while(!q.empty()){ // BFS
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            ans[r][c]=steps;  // updating ans

            for(int i=0;i<4;i++){
                int nr=r+xm[i];
                int nc=c+ym[i];

              if(nc>=0 && nr>=0 && nr<n && nc<m && vis[nr][nc]==0){ // operating within boundary conditions
                vis[nr][nc]=1;
                q.push({{nr,nc},steps+1});
              } 
            }
        }
        return ans;
    }
};