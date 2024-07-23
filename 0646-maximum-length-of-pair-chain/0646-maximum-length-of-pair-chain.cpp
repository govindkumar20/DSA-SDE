class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if (n == 0) return 0;

        // Sort pairs based on the second element
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Use a greedy approach to find the longest chain
        int currEnd = INT_MIN;
        int chainLength = 0;

        for (const auto& pair : pairs) {
            if (pair[0] > currEnd) {
                chainLength++;
                currEnd = pair[1];
            }
        }

        return chainLength;
    }
};
