class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> ans(n,INT_MAX);
        for(auto i:richer){
           adj[i[0]].push_back(i[1]);
           indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            ans[i]=i;
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                if(ans[i]==INT_MAX || quiet[ans[i]]>quiet[ans[node]]) ans[i]=ans[node];
                if(--indegree[i]==0) q.push(i);
            }
        }
        return ans;
    }
};