class Solution {
public:

// dijkstra's algorithm with maxheap so that the maximum probability stays at top
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double> dist(n,INT_MIN);
        priority_queue<pair<double,int>> q; //probability,node
        dist[start]=1;
        q.push({1.0,start});
        while(!q.empty()){
            double dis=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto i:adj[node]){
                double edgW=i.second;
                int adjNode=i.first;
                if(edgW*dis>dist[adjNode]){
                    dist[adjNode]=edgW*dis;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
       // return dist[end]==0? 0.00000:dist[end];
       if(dist[end]==INT_MIN) return 0.00000;
       else return dist[end];
    }
};