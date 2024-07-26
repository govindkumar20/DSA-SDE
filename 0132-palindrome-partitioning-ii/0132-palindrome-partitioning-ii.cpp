//matrix chain multiplication varient

class Solution {
public:
    int dp[2001][2001];

    bool ispalindrome(string& s,int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int solve(string & s,int i, int j){
        if(i>=j) return 0; // base condtn

        if(dp[i][j]!=-1) return dp[i][j]; // memo

        if(ispalindrome(s,i,j)) return 0; // no need of partition

        int ans=INT_MAX;
        for(int k=i;k<j;k++){  // k is partition
            if(ispalindrome(s,i,k)){
                ans=min(ans,1+solve(s,k+1,j));
            }
        }
        return dp[i][j]=ans;
    }

    int minCut(string s) {
      memset(dp,-1,sizeof(dp));
       return solve(s,0,s.size()-1);
    }
};