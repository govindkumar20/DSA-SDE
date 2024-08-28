class Solution {
public:
   vector<pair<int,int>> temp;
    bool static  cmp(const pair<int,int> a, const pair<int,int> b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second>b.second;
    }

   void dkstr(int n,int src,vector<pair<int,int>> adj[],vector<vector<int>>& edges, int distanceThreshold){
    vector<int> dist(n,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; //weight,node
    dist[src]=0;
    q.push({0,src});
    while(!q.empty()){
        int node=q.top().second;
        int weight=q.top().first;
        q.pop();
        for(auto i:adj[node]){
            int adjNode=i.first;
            int edgW=i.second;
            if(weight+edgW<dist[adjNode]){
                dist[adjNode]=weight+edgW;
                q.push({weight+edgW,adjNode});
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
    if(i!=src && dist[i]<=distanceThreshold) count++;
    }
    temp.push_back({count,src});
   }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        for(int i=0;i<n;i++){
            dkstr(n,i,adj,edges,distanceThreshold);
        }
        sort(temp.begin(),temp.end(),cmp);
        return temp[0].second;
    }
};