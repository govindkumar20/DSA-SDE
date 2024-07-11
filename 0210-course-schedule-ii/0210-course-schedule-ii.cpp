class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<int> v;
        unordered_map<int,vector<int>> m;
        for(auto i:prerequisites){
            m[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;
        int processed=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            v.push_back(temp);
            q.pop();
            processed++;
            for(auto i:m[temp]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(processed==n) return v;
        else return {};
    }
};