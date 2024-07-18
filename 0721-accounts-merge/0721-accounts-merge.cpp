//mind fuckin ques

class disjoint
{
    public:
    vector<int>parent;
    vector<int>size;
    disjoint(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findulp(int node)
    {
        if(parent[node]==node)
        return node;
        return parent[node]=findulp(parent[node]);
    }
    void unionbysize(int u, int v)
    {
        int ulp_u=findulp(u);
        int ulp_v=findulp(v);
        if(ulp_u==ulp_v)
        return;
        else if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint ds(n);
        unordered_map<string ,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(m.find(mail)==m.end()) m[mail]=i;
                else ds.unionbysize(i,m[mail]); 
            }
        }

        vector<string> merged[n];
        for(auto it:m){
            string mail=it.first;
            int node=ds.findulp(it.second);
            merged[node].push_back(mail);
        }
        
         vector<vector<string>> ans;
         for(int i=0;i<n;i++){
          if(merged[i].size()==0) continue;
          sort(merged[i].begin(),merged[i].end());
          vector<string> temp;
          temp.push_back(accounts[i][0]);
          for(auto it:merged[i]){
            temp.push_back(it);
          }
          ans.push_back(temp);
         }

   return  ans;
    }
};