
class disjoint{
    public:
    vector<int> parent;
    vector<int> size;
    disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=i;
        }
    }
        int findulp(int node){
            if(parent[node]==node) return node;
            return parent[node]=findulp(parent[node]);
        }
        void unionbysize(int u,int v){
            int ulp_u=findulp(u);
            int ulp_v=findulp(v);
            if(ulp_u==ulp_v) return;
            else if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            } else{
                 parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
     }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        disjoint ds(n);
        for(auto i:pairs){
            ds.unionbysize(i[0],i[1]);
        }
        map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[ds.findulp(i)].push_back(i);
        }

        for(auto i:m){
            vector<int> v=i.second;
            string temp="";
            for(auto j:i.second){
                temp+=s[j];
            }
            sort(temp.begin(),temp.end());
            for(int k=0;k<temp.size();k++){
                s[v[k]]=temp[k];
            }

        }
        return s;
    }
};