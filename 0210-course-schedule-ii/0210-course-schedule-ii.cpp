class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        vector<int> topo;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        int processed=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            processed++;
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);

            }
        }
        if(processed==n) return topo;
        return {};
    }
};