class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> outdegree(V,0);
        vector<int> safe(V);
        vector<int> ans;
        vector<vector<int>> l(V);
         queue<int> q;
        for(int i=0;i<V;i++){
            for(auto val:graph[i]){   // male a vector list jisme node and uske upar incoming edges nodes ho 
                l[val].push_back(i);   // kyunki hame subtract krni hogi outdegree after deleting dafe nodes
            }
                outdegree[i]=graph[i].size();
                if(outdegree[i]==0)  q.push(i);
            
        }
       
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe[node]=1;  // keeping safenodes in memory
            for(auto i:l[node]){
                outdegree[i]--; // outdegree-- after deleting safe node
                if(outdegree[i]==0) q.push(i);
            }
        }
        for(int i=0;i<V;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};