class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,-1));
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                } 
            }
         }

         while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int p=0;p<4;p++){
                int newr=r+xm[p];
                int newc=c+ym[p];
                if(newr>=0 && newr<=n-1 && newc>=0 && newc<=m-1 && ans[newr][newc]==-1){
                    q.push({newr,newc});
                    ans[newr][newc]=ans[r][c]+1;
                }
            }
            
         }
         return ans;
    }
};