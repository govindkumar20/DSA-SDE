class Solution {
public:
    vector<pair<int,int>> adj[101];
    vector<pair<int,int>> ans;
        bool static cmp(const pair<int,int> p1 ,const pair<int,int> p2){  // comparator func for sorting
        if(p1.first != p2.first)
            return p1.first < p2.first;
        
        return p1.second > p2.second;
    }
    void dkstr(int src,int n,  vector<vector<int>>& edges,int threshold){
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,src});
        dist[src]=0;
        while(!q.empty()){
            int d=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgW=it.second;
                if(d+edgW<dist[adjNode]){
                    dist[adjNode]=d+edgW;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){                      // cities that lies at dist less than threshold to source
            if(i!=src && dist[i]<=threshold){
                count++;
            }
        }
        ans.push_back({count,src});
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto i:edges){    // adj list (bidirectional)
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        for(int i=0;i<n;i++){   // dijkastra for each node
            dkstr(i,n,edges,distanceThreshold);
        }
      sort(ans.begin(),ans.end(),cmp);  //will give max neighbours city
      return ans[0].second;
    }
};