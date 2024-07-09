class Solution {
public: 
// definately not ans easy one
     int solve(vector<int>& arr,vector<vector<int>>& dp, int i, int j){
       
        if(i==j) return 0;
        priority_queue<int> q(arr.begin()+i,arr.begin()+j+1);
        if(dp[i][j]!=-1) return dp[i][j];
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        int sum=INT_MAX;
         int prod=a*b;
        for(int p=i;p<j;p++){
            sum=min(sum,solve(arr,dp,i,p)+solve(arr,dp,p+1,j));
        }
        return dp[i][j]=sum+prod;
     }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(arr,dp,0,n-1);
    }
};