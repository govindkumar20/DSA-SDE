class Solution {
public:
    int solve(vector<int>& arr, vector<vector<int>> & dp, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int temp=solve(arr,dp,i,k-1)+solve(arr,dp,k+1,j)+(arr[i-1]*arr[k]*arr[j+1]);
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        for(auto i:nums) arr.push_back(i);
        arr.push_back(1);
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        return solve(arr,dp,1,arr.size()-2);
    }
};