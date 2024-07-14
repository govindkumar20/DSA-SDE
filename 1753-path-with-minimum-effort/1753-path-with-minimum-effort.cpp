#define pair pair<int, pair<int,int>>

class Solution {
public: vector<int> xm={-1,0,1,0}; // 4 drn for travelling
        vector<int> ym={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        priority_queue<pair,vector<pair>,greater<pair>> q; // min_heap bcz we want min effort to stay at top
        vis[0][0]=0; // initial constraints
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
                if(nr>=0 && nr<n && nc>=0 && nc<m ){
                    int nd=max(d,abs(heights[nr][nc]-heights[r][c])); // we want max absolute dist between adj cells
                    if(nd<vis[nr][nc]){  // if that dist is less then present val then present value = that dist
                        vis[nr][nc]=nd; 
                        q.push({nd,{nr,nc}}); // push that in q
                    }
                }
            }


        }
        return 0;
    }
};