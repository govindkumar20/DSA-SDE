class Solution {
public:

    bool isvalid(vector<int>& p1 , vector<int>& p2){   // func to check whether row or column same
        if(p1[0]==p2[0]) return true;
        if(p1[1]==p2[1]) return true;
        return false;
    }
    void dfs(int ind, vector<int>& vis,int n,vector<vector<int>>& stones){ // basic dfs
        vis[ind]=1;
        for(int i=0;i<n;i++){
            if(!vis[i] && isvalid(stones[ind],stones[i])){   // if row or col same then go for dfs
                dfs(i,vis,n,stones);
            }
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        //calculate the number of components and subtract it from no of nodes
        int n=stones.size();
        vector<int> vis(n,0);
        int count=0;         //component count
        for(int i=0;i<n;i++){
            if(!vis[i]){
            count++;     // if its a component count++
            dfs(i,vis,n,stones);
            }
        }
        return n-count;
    }
}; 