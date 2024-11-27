class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for(auto i: edges){
            indegree[i[1]]++;
        }
        int count=0;
        int ans=-1;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                count++;
                ans=i;
            } 
        }
        if(count==1) return ans;
        return -1;
    }
};