class Solution {
public:
    vector<int> xm={-2,-2,-1,-1,1,1,2,2}; // 8 vertices of possible moves for night
    vector<int> ym={-1,1,-2,2,-2,2,-1,1};
    double dp[26][26][102]; //3d dp acc ro me
    double solve(int i,int j, int n, int k){
        if(i<0 || j<0 || i>=n || j>=n ) return 0; // boundary condtn
        if(k==0) return 1; // no more moves pending
        if(dp[i][j][k]!=-1.0) return dp[i][j][k]; // memo
        double ans=0;
        for(int p=0;p<8;p++){ // traverse all a8 moves and do it again for every 8 moves 
            ans+=solve(i+xm[p],j+ym[p],n,k-1); // basically recursion
        }
        return dp[i][j][k]=ans; // insert back into dp
    }


    double knightProbability(int n, int k, int row, int column) {
      //  double dp[26][26][102];
      memset(dp,-1,sizeof(dp));
        for(int i=0;i<26;i++){    // filling the dp array with -1
            for(int j=0;j<26;j++){
                for(int k=0;k<102;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        double fc=solve(row,column,n,k);   // old school probability
        double tc=pow(8,k);
        return fc/tc;
        

    }
};