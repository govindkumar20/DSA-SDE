class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);
        for(auto i:trust){
            indegree[i[1]]++;
            outdegree[i[0]]++;
        }

      for(auto i:indegree) cout<<i<<" ";
      cout<<endl;
      for(auto i:outdegree) cout<<i<<" ";


        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                return i;
            }
        }
        return -1;
    }
};