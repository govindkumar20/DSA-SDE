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
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        } else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        disjoint ds(n);
       for(int i=1;i<=n;++i)
		for(int j=1;j<=sqrt(i);++j)
			if(i%j==0)
			{
				if(j>threshold)
					ds.unionbysize(j,i);
				if((i/j)>threshold)
					ds.unionbysize(i/j,i);
			}
        int m=queries.size();
        vector<bool> ans(m,false);
        for(int i=0;i<m;i++){
            if(ds.findulp(queries[i][0])==ds.findulp(queries[i][1])) ans[i]=true;
        }
        return ans;
    }
};