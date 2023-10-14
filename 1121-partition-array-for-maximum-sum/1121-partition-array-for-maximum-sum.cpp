class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,n,k,dp);
    }

    int solve(int i,vector<int>& arr, int& n, int & k,vector<int> & dp)
    {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxelement=INT_MIN;
        int maxsum=INT_MIN;
        int length=0;
        for(int j=i;j<min(n,i+k);j++)
        {
            length++;
            maxelement=max(maxelement,arr[j]);
            int sum=(length*maxelement)+solve(j+1,arr,n,k,dp);
            maxsum=max(maxsum,sum);
        } 
        return dp[i]= maxsum;
    }
   
};
