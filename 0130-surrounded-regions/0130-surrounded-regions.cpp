class Solution {
public:
    vector<int> xm={-1,0,1,0}; // coordinates of 4 drn's
    vector<int> ym={0,1,0,-1};
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j){  // simple old dfs
        int n=board.size();
        int m=board[0].size();
        if(i>=0 && j>=0 && i<n && j<m && vis[i][j]==0  && board[i][j]=='O'){
            vis[i][j]=1;
            for(int p=0;p<4;p++){
                dfs(board,vis,i+xm[p],j+ym[p]);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)); // visited array

           // traverse each boundary and if there exist O , apply dfs and we cannot change this cell and its  connected cells
        for(int j=0;j<m;j++){ 
            if(board[0][j]=='O' && vis[0][j]==0)  dfs(board,vis,0,j);  
            if(board[n-1][j]=='O' && vis[n-1][j]==0)  dfs(board,vis,n-1,j);
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i][0]==0) dfs(board,vis,i,0);
            if(board[i][m-1]=='O' && vis[i][m-1]==0)  dfs(board,vis,i,m-1);
        }

        for(int i=0;i<n;i++){    // if there exist a surrounding regin, make it X
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }


    }
};   