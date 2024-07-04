class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int> s(days.begin(),days.end());// insert into set so that we can find
        vector<int> dp(366);
        for(int i=1;i<366;i++){ // iterate through all daya in a year

            dp[i]=dp[i-1];  // travelling day or not doesnt matter just carry prev days cont along with
            if(s.find(i)!=s.end()){ //if ita a travelling day choose minimum
                dp[i]=min(dp[i-1]+costs[0],
                min(
                dp[max(i-7,0)]+costs[1],// max(i-days,0) to avoid negative like what if i-7<0 in this case choose 0
                dp[max(i-30,0)]+costs[2]));
            }
        }
        return dp[365]; // min cost at the end of the year
    }
};