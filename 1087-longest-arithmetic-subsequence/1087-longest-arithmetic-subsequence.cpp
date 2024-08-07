class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int len = 2;
        vector<unordered_map<int, int>> dp(n);
        // LIS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                len = max(len, dp[i][diff]);
            }
        }
        return len;
    }
};

/*
This problem is similar to Longest Increasing Subsequence problem. The
difference is that we need to consider the arithmetic difference in this
problem. How to keep track of the length as well as the difference? We can use a
hashmap, whose key is the difference and value is the length. Then we can solve
the problem with dynamic programming: As noted in the problem description, 2 <=
A.length, so we don't need to consider the edge case when there is no element or
only one element in A. The base case is A.length == 2, then A itself is the
longest arithmetic subsequence because any two numbers meet the condition of
arithmetic. The optimization step is that for two elements A[i] and A[j] where j
< i, the difference between A[i] and A[j] (name it diff) is a critical
condition. If the hashmap at position j has the key diff, it means that there is
an arithmetic subsequence ending at index j, with arithmetic difference diff and
length dp[j][diff]. And we just add the length by 1. If hashmap does not have
the key diff, then those two elements can form a 2-length arithmetic
subsequence. And update the result if necessary during the iteration.
*/