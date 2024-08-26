class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> safeNodes(n,0);
    queue<int> q;
    vector<vector<int>> adj(n);
    vector<int> outdegree(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            adj[graph[i][j]].push_back(i);
        }
        outdegree[i]=graph[i].size();
        if(outdegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        safeNodes[node]=1;
        for(auto i:adj[node]){
            outdegree[i]--;
            if(outdegree[i]==0) q.push(i);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(safeNodes[i]==1) ans.push_back(i);
    }
     return ans;
    }
};