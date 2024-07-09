class Solution {
public:
   // raat me jb 3am dimag kharab hota hai to refresh hone ke liye aise comments kr deta hoon, peace !!
    #define MOD 1000000007
    
    vector<int> xm = {-1, 0, 1, 0}; //  bro vectors me coordinates hai 4 directions ke
    vector<int> ym = {0, 1, 0, -1};

    int solve(int i, int j, int m, int n, int k, vector<vector<vector<int>>>& dp) { // u being called bro
        if (i < 0 || j < 0 || i >= m || j >= n) return 1; // agar bahr gya to 1 return krva dena bro vrna mujse pitega tu
        if (k == 0) return 0; // agar moves khthm ho gye to 0 return krva dena bro
        if (dp[i][j][k] != -1) return dp[i][j][k]; // memoization bro to save time , nhi kiya to TLE bhag bhag kr ayegi

        int ans = 0; // ye ans hai bro
        for (int p = 0; p < 4; p++) {  // loop hai bro kyunki 4 possible directions to travel 
            ans = (ans + solve(i + xm[p], j + ym[p], m, n, k - 1, dp)) % MOD; // recursive calls ko ans me add kr dena bro
            // ye MOD kb picha chedega mera (crying emoji) , i hate MOD ,my fuckin old enemy 
        }
        return dp[i][j][k] = ans; // dp table ko update kr dena bro and ans bhi return krva dena end me
    }

    int findPaths(int m, int n, int k, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));  // bro 3D dp
        return solve(startRow, startColumn, m, n, k, dp); // calling another bro
    }
};
