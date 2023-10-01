class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //first buy.....first sell.....second buy....second sell
        int fb=INT_MIN;
        int sb=INT_MIN;
        int fs=0;
        int ss=0;
        for(int i=0;i<prices.size();i++)
        {
            fb=max(fb,-prices[i]);
            fs=max(fs,fb+prices[i]);
            sb=max(sb,fs-prices[i]);
            ss=max(ss,sb+prices[i]);
        }
        return ss;
    }
};