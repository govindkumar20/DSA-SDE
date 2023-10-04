/*
dp[len][2]
case1: we have a stock on i day,dp[i][1]
---purchased on i th day
    dp[i-2][0]-prices[i]
---carry forwarding
    dp[i-1][1]

case2: we do not have a stock on i day, dp[i][0]
---sold it today
   dp[i-1][1]+prices[i]
---did nothing
   dp[i-1][0]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<=1) return 0;
        if(len==2 && prices[0]<prices[1]) return prices[1]-prices[0];
        if(len==2 && prices[0]>prices[1]) return 0;

        vector<vector<int>> dp(len,vector<int>(2));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        dp[1][0]=max(dp[0][0],dp[0][1]+prices[1]);
        dp[1][1]=max(dp[0][1],dp[0][0]-prices[1]);

        for(int i=2;i<len;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
        }
        return dp[len-1][0];
    }
};