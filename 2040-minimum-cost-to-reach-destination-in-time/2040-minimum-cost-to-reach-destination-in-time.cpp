#define pairs pair<int,pair<int,int>>
class Solution {
public:
//dijkstras
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<pair<int,int>> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pairs,vector<pairs>,greater<pairs>> q; //passingfee,node,time
        vector<int> cost(n,1e9);
        q.push({passingFees[0],{0,0}});
        cost[0]=0;
        while(!q.empty()){
            int fee=q.top().first;
            int node=q.top().second.first;
            int time=q.top().second.second;
            q.pop();
            if(node==n-1) return fee;
            for(auto i:adj[node]){
                int adjNode=i.first;
                int t=i.second;
                if(t+time<cost[adjNode] && t+time<=maxTime){
                    cost[adjNode]=t+time;
                    q.push({passingFees[adjNode]+fee,{adjNode,t+time}});
                }
                
            }
        }
      return -1;
    }
};