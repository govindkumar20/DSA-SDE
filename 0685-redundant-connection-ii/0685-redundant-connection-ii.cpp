class Solution {
public:

// erase each edge and check ehether topo sort is possible if yes we have got ans otherwise insert that erased node
//if topo is possible after erasing edge that means that edge is additional
// start traversing edges from behind bcz we want to return the answer that occurs last in the given 2D-array.
    bool topo(vector<set<int>>& g,int n){
        vector<int> indegree(n+1,0);
        for(int i=1;i<=n;i++){
            for(auto& it:g[i]) indegree[it]++;
        }
        
        queue<int> q;
        int processed=0;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0) q.push(i);
        }
        if(q.size()>1) return false;
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int node=q.front();
            q.pop();
            processed++;
            for(auto& i:g[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        }
        return processed==n;
        
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<set<int>> g(n+1);
        for(auto i:edges){
            g[i[0]].insert(i[1]);
        }
        for(int i=n-1;i>=0;i--){
            int u=edges[i][0];
            int v=edges[i][1];
            g[u].erase(v);
            if(topo(g,n)) return {u,v};
            g[u].insert(v);
        }
        return {-1,-1};
    }
};