class Solution {
public:
    int solve(int e,int f,vector<vector<int>>& dp){
        if(f==0 || f==1) return f;
        if(e==1) return f;
        int ans=INT_MAX;
        if(dp[e][f]!=-1) return dp[e][f];
        int s=1;int end=f;
        while(s<=end)
        {
            int k=s+(end-s)/2;
            int a=solve(e-1,k-1,dp);
            int b=solve(e,f-k,dp);
            int temp_ans=1+max(a,b);
            ans=min(ans,temp_ans);
            if(a>b) end=k-1;
            else s=k+1;
        }
        return dp[e][f]=ans;
    }

    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e+1,vector<int>(f+1,-1));
        return solve(e,f,dp);
    }
};