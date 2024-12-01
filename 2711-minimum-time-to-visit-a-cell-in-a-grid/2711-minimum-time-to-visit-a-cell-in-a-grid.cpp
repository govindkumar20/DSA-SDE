#define p pair<int,pair<int,int>>
class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<p,vector<p>,greater<p>> q;
        q.push({0,{0,0}});
        while(!q.empty()){
            int curr=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            if(r==n-1 && c==m-1) return curr;
            for(int i=0;i<4;i++){
                int nr=r+xm[i];
                int nc=c+ym[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m  ){
                    int wait_time = (grid[nr][nc] - curr) % 2 == 0 ? 1 : 0;
                    int new_time = max(curr + 1, grid[nr][nc] + wait_time);
                    if(new_time<dist[nr][nc]){
                        dist[nr][nc]=new_time;
                        q.push({new_time,{nr,nc}});
                    }

                }
            }
        }
    return -1;
    }
};