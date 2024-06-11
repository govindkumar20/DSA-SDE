class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0 || s[0]=='0') return 0;
        vector<int> dp(n+1,0);  // dp will store no of ways
        dp[0]=1; // no of ways to decode an empty string is 1
        dp[1]=1; // no of ways to decode an string of length 1  is 1
        for(int i=2;i<=n;i++){
            if(s[i-1]>='1' && s[i-1]<='9') dp[i]=dp[i-1];  // single char
            if(s[i-2]=='1' || s[i-2]=='2' && (s[i-1]<='6')) dp[i]+=dp[i-2]; // double char

        }
        return dp[n];
    }
};