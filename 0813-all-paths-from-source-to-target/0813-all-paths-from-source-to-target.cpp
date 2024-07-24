class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& path, int node, int target){
        path.push_back(node);
        if(node==target) ans.push_back(path);  // path found
        else{
            for(auto i:graph[node]){
                dfs(graph,ans,path,i,target);
                path.pop_back();  // backtrack to explore other paths
            }
        }
       for(auto i:path) cout<<i<<" ";   //see this to see backtracking logic
       cout<<endl;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> ans;
        vector<int> path;
         dfs(graph,ans,path,0,graph.size()-1);
         return ans;
    }
};