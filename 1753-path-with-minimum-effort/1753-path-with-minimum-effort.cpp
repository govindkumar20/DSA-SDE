#define pair pair<int,pair<int,int>>
class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair,vector<pair>,greater<pair>> q;
        dist[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int r=q.top().second.first;
            int c=q.top().second.second;
            int d=q.top().first;
            q.pop();
            if(r==n-1 && c==m-1) return d;
            for(int i=0;i<4;i++){
                int nr=r+xm[i];
                int nc=c+ym[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int effort=max(d,abs(heights[nr][nc]-heights[r][c]));
                    if(effort<dist[nr][nc]) {
                    dist[nr][nc]=effort;
                    
                    q.push({effort,{nr,nc}});
                }
                }
            }
        }
        return 0;
    }
};