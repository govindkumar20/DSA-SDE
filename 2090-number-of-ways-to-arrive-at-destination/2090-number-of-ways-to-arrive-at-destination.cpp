#define mod 1000000007


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<long long> dist(n, 1e18);  // Initialize with a large value
        vector<long long> ways(n, 0);     // Initialize ways to 0
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> q; // {time, node}
        
        dist[0] = 0;
        ways[0] = 1;  // Start at node 0 with 1 way to get there
        q.push({0, 0});
        
        while (!q.empty()) {
            long time = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for (auto i : adj[node]) {
                int adjNode = i.first;
                long long edgeW = i.second;
                
                if (time + edgeW < dist[adjNode]) {
                    dist[adjNode] = time + edgeW;
                    ways[adjNode] = ways[node];  // Update ways to reach adjNode
                    q.push({dist[adjNode], adjNode});
                } else if (time + edgeW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;  // Increment ways modulo mod
                }
            }
        }
        
        return ways[n-1] % mod;  // Return the number of ways to reach the last node
    }
};