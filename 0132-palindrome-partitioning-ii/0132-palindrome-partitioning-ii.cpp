class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,n,dp)-1;
    }

    int solve(int i,string& s,int& n, vector<int> & dp)
    {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mincost=INT_MAX;
        vector<char> temp;
        for(int j=i;j<n;j++)
        {
            temp.push_back(s[j]);
            if(ispalindrome(temp))
            {
                 int cost=1+solve(j+1,s,n,dp);
                 mincost=min(mincost,cost);
            }
        }
        return dp[i]= mincost;
    }

    bool ispalindrome(vector<char> & temp)
    {

        int i=0;
        int j=temp.size()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};