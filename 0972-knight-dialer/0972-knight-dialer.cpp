class Solution {
public:
#define MOD 1000000007
 vector<int> xm={-2,-2,-1,-1,1,1,2,2}; // 8 vertices of possible moves for Knight
    vector<int> ym={-1,1,-2,2,-2,2,-1,1};
     long dp[5001][4][3]= {{{0}}}; // DP INITIALIZED TO 0
     
    long solve(int i, int j, int n){
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j!=1)) return 0; // BOUNDARY CASES
        if(n==1) return 1;
        if(dp[n][i][j]>0) return dp[n][i][j]; // MEMO
        long ans=0;
        for(int p=0;p<8;p++){  // BCZ 8 MOVES ARE THERE FOR CONSIDERATION
        ans=(ans+solve(i+xm[p],j+ym[p],n-1))%MOD;// RECURSION AND adding in ans
        }
        return dp[n][i][j]=ans; // storing  values in dp table

    }
    int knightDialer(int n) {
       // long dp[][][]= new long [n+1][4][3];
        long s=0;
        for(int i=0;i<4;i++){  // any digit can form a number
            for(int j=0;j<3;j++){
                s=(s+solve(i,j,n))%MOD;
            }
        }
        return (int) s;
    }
};