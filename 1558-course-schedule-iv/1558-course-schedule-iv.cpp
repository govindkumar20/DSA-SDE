// basic topological sort

class Solution {
public:
    // bool dfs(int a, int b,vector<vector<int>>& adj,int n,vector<int>& vis){  // if u can visit node node b from node a
    //     vis[a]=1;
    //     if(a==b) return true;
    //     for(auto i:adj[a]){
    //         if(!vis[i]){
    //            if( dfs(i,b,adj,n,vis))  return true;
    //         }
    //     }
    //     return false;
    // }


     bool bfs(int node, int target, vector<vector<int>>& adj, int n){ 

        queue<int> q;
        vector<int> vis(n,0);
        vis[node]=1;
        q.push({node});

        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num==target) return true;

            for(auto it: adj[num]){
                if(vis[it]==0){
                    if(it==target) return true;
                    q.push(it); vis[it]=1;
                }
            }
        }
    return false;
     } 

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<bool>ans(m,false);
        if(prerequisites.size()==0) return ans;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]); // adjacency list
            indegree[i[1]]++;          // indegree array
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                if(--indegree[i]==0) q.push(i);
            }
        }
        
        
       for(int i=0;i<queries.size();i++){
        int a=queries[i][0];
        int b=queries[i][1];
        for(int j=0;j<topo.size();j++){
            
            if(topo[j]==a &&  bfs(a,b,adj,n)){
                ans[i]=true;
                break;
            }
            if(topo[j]==b){
                break;
            }
        }
    }
    return ans;
    }
};