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
        else return parent[node]=findulp(parent[node]);
    }
    void unionbysize(int u, int v){
        int ulp_u=findulp(u);
        int ulp_v=findulp(v);
        if(ulp_u==ulp_v) return;
        else if(ulp_u<ulp_v){
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
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        disjoint ds(*max_element(nums.begin(),nums.end())+1);
        unordered_map<int,int> m;
        for(auto c:nums){
            for(int i=2;i<=sqrt(c);i++){
                if(c%i==0){
                    ds.unionbysize(c,i);
                    ds.unionbysize(c,c/i);
                }
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
             ans=max(ans,++m[ds.findulp(nums[i])]);
        }
       return ans;
    }
};