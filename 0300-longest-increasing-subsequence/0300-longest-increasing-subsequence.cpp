// LCS of array and unique ascending elements of array gives LIS 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums1) {
        int n=nums1.size();
        set<int> s(nums1.begin(),nums1.end());  // for unique elements and ascending order
        vector<int> nums2(s.begin(),s.end());
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};