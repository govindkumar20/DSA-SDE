class Solution {
public: 
    bool bfs(vector<vector<int>>& graph, vector<int>& vis, int start) {
        queue<int> q;
        q.push(start);
        vis[start] = 0; // Start coloring with group 0
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (vis[neighbor] == -1) {
                    vis[neighbor] = !vis[node]; // Assign opposite group color
                    q.push(neighbor);
                } else if (vis[neighbor] == vis[node]) {
                    return false; // Conflict found (same group)
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1); // -1 means unvisited, 0 and 1 are two different groups
        
        for (int i = 0; i < V; ++i) {
            if (vis[i] == -1) { // If not visited
                if (!bfs(graph, vis, i)) {
                    return false; // Graph is not bipartite
                }
            }
        }
        
        return true; // Graph is bipartite
    }
};
