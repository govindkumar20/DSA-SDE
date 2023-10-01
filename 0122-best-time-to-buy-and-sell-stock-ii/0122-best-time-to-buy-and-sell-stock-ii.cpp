class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long maxprofit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>=prices[i-1])
            {
                maxprofit+=prices[i]-prices[i-1];
            }
        }
        return maxprofit;
    }
};