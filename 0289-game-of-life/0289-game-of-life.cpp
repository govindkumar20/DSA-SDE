class Solution {
public:
      int live(vector<vector<int>>&v, int i, int j , int n , int m)
      {
        int count=0;
        if(i>0) {
            if(v[i-1][j]==1) count++;
        }
         if(i<n-1) {
            if(v[i+1][j]==1) count++;
        }
         if(j>0) {
            if(v[i][j-1]==1) count++;
        }
         if(j<m-1) {
            if(v[i][j+1]==1) count++;
        }
         if(i>0 && j>0) {
            if(v[i-1][j-1]==1) count++;
        }
        if(i<n-1 && j<m-1) {
            if(v[i+1][j+1]==1) count++;
        }
        if(i>0 && j<m-1) {
            if(v[i-1][j+1]==1) count++;
        }
        if(i<n-1 && j>0) {
            if(v[i+1][j-1]==1) count++;
        }
        return count;
      }


    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> dp=board;
    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
             int sum=live(dp,i,j,n,m);
                if(board[i][j]==0)
                {
                    if(sum==3) board[i][j]=1; 
                } else if(board[i][j]==1){
                    if(sum<2 || sum>3) board[i][j]=0;
                }
            }
        }
      
       
    }
};