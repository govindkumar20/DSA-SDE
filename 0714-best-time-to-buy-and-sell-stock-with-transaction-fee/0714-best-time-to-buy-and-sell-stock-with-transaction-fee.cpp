class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
     int len=prices.size();
     if(len<=1) return 0;

     vector<int> buy(len,INT_MIN);
     vector<int> sell(len,0);

     buy[0]=-prices[0];

     for(int i=1;i<len;i++)
     {
       buy[i]=max(buy[i-1],sell[i-1]-prices[i]);
       sell[i]=max(sell[i-1],buy[i-1]+prices[i]-fee);
     }
     return sell[len-1];

    }
};