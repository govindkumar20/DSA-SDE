class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int minSoFar=prices[0];
        for(int i=0;i<n;i++)
        {
           minSoFar=min(minSoFar,prices[i]);
           maxprofit=max(maxprofit,prices[i]-minSoFar);
        }
        return maxprofit;
    }
};