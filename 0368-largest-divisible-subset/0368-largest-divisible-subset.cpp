class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> result;
        while (hash[lastIndex] != lastIndex) {
            result.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        result.push_back(nums[lastIndex]);
        reverse(result.begin(), result.end());
      cout<<maxi;
        return result;
    }
};
