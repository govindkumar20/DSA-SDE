class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //fuckin same as sumsets with minimum diff
        //  x==y , x<y ,, x!=y ye sbb bss pagal bnane ke liye likha hai
        int sum=0;
        for(auto i:stones) sum+=i;
        int n=stones.size();
        int m=sum;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int j=1;j<=m;j++) dp[0][j]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j-stones[i-1]]|| dp[i-1][j]; 
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

         int mini=INT_MAX;
        for(int j=0;j<=m/2;j++){
            if(dp[n][j]==true){
                int diff=abs(j-(sum-j));
                mini=min(mini,diff);
            }
        }
        return mini;
    }
};