class Solution {
public:
    int solve(vector<int>& dp,vector<int>& sum,int n){
        if(n<0) return 0;
        if(n==0) return sum[0];
        if(dp[n]!=-1) return dp[n];
        int take=sum[n]+solve(dp,sum,n-2);
        int nonTake=solve(dp,sum,n-1);
        return dp[n]=max(take,nonTake);
    }


   
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> sum(n,0);
        for(auto i:nums) sum[i]+=i;
        vector<int> dp(n+1,-1);
        return solve(dp,sum,sum.size()-1);
    }
};