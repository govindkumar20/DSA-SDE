class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // making adj list and indegree vector
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> adj;
        for(auto &pair:prerequisites){
            adj[pair[1]].push_back(pair[0]);
            indegree[pair[0]]++;
        }

        queue<int> q;

        // push node with indegree 0 as it doesnt depent on anyone
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int processed=0;
        // BFS
        while(!q.empty()){
            int node=q.front();
            q.pop();
            processed++;
            for(auto i:adj[node]){  
                indegree[i]--;   // as node vanishes, remove its dependencies from others thats why indegree--;
                if(indegree[i]==0) q.push(i); // when node become independent i.e indegree==0 insert it into queue
            }
        }
        return processed==n;
    }
    
};

/*

    ex:-           0                   // independent
          (-1)  /    \   (-1)
               1       2
               |       |    
               3       4
                 \    /
                    5 

*/