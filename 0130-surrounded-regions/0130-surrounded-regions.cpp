class Solution {
public:
   vector<int> xm={-1,0,1,0};
   vector<int> ym={0,1,0,-1};
   void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board){
    int n=board.size();
    int m=board[0].size();
    if(i>=0 || i<n || j>=0 || j<m || board[i][j]!='O' || vis[i][j]) return;
    vis[i][j]=1;
    for(int p=0;p<4;p++){
    dfs(i+xm[p],j+ym[p],vis,board);
    }
   }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++) {
            if(board[0][j]=='O') dfs(0,j,vis,board);
        }
        for(int j=0;j<m;j++) {
            if(board[n-1][j]=='O') dfs(n-1,j,vis,board);
        }
        for(int i=1;i<n-1;i++){
              if(board[i][0]=='O') dfs(i,0,vis,board);
        }
        for(int i=1;i<n-1;i++) {
            if(board[i][m-1]=='O')  dfs(i,m-1,vis,board);
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
            }
          
        }
        

    }
};