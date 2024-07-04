class Solution {
private:
    void dfs(int node, vector<int> adjls[], vector<int>& vis){ // simple dfs
        vis[node]=1;
        for(auto i:adjls[node]){
            if(!vis[i]){
                dfs(i,adjls,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& v) {
         int n=v.size();
        // make adj matrix to adj list 
        vector<int> adjls[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
       
        int count=0;
        vector<int> vis(n,0);  // visited list
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                count++;
                dfs(i,adjls,vis);
            }
        }
        return count;
    }
};