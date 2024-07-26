class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        // Create a vector of pairs (degree, node)
        vector<pair<int, int>> nodesWithDegree;
        for (int i = 0; i < n; ++i) {
            nodesWithDegree.push_back({degree[i], i});
        }

        // Sort nodes based on degree in descending order
        sort(nodesWithDegree.begin(), nodesWithDegree.end(), greater<pair<int, int>>());

        // Assign importance values
        vector<int> importance(n);
        for (int i = 0; i < n; ++i) {
            importance[nodesWithDegree[i].second] = n - i;
        }

        // Calculate the total importance
        long long ans = 0;
        for (const auto& road : roads) {
            ans += importance[road[0]] + importance[road[1]];
        }

        return ans;
    }
};
