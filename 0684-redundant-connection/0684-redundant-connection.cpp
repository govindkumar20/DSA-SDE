class disjoint{    //simple dsu
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjoint ds(n);
        for(auto i:edges){
            if(ds.findulp(i[0])==ds.findulp(i[1])) return {i[0],i[1]}; //agr ultimate parents same hai to mtlb cycle hai and usko todna hai toh ye hamara ans ho jayega
            else ds.unionbysize(i[0],i[1]); //agr cycle nhi bn rhi to union kr do
        }
        return {};
    }
};