class Solution {
public:
   bool isvalid(vector<int>& a,vector<int>& b){
    if(a[0]==b[0]) return true;
    if(a[1]==b[1]) return true;
    return false;
   }

    void dfs(int n,int node,vector<int>& vis,vector<vector<int>>& stones){
        vis[node]=1;
        for(int i=0;i<n;i++){
            if(!vis[i] && isvalid(stones[i],stones[node])){
                dfs(n,i,vis,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(n,i,vis,stones);
                count++;
            }
        }
        return n-count;
    }
};