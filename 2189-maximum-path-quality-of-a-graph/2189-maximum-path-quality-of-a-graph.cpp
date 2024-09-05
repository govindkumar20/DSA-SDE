class Solution {
public:
    void dfs(int node,vector<int>& values,vector<vector<pair<int,int>>>& adj,int maxTime, int& ans,int time,int quality ){
        if(time>maxTime) return;
        quality+=values[node];
        if(node==0) ans=max(quality,ans);
        int temp=0;
        swap(temp,values[node]); //to avoid double counting of nodes
        for(auto i:adj[node]){
            dfs(i.first,values,adj,maxTime,ans,time+i.second,quality);
        }
        swap(temp,values[node]);
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>> adj(n);
        int ans=0;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        dfs(0,values,adj,maxTime,ans,0,0);
        return ans;
    }
};