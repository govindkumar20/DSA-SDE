class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar=prices[0];
        int maxprofit=0;

        // store min stock value and  sell stock everyday to find max profit
        for(int i=0;i<prices.size();i++)
        {
            minsofar=min(minsofar,prices[i]);       
            maxprofit=max(maxprofit,prices[i]-minsofar);
        }
        return maxprofit;
    }
};