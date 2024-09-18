class disjoint {
public:
    vector<int> parent;
    vector<int> size;
    
    disjoint(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = i; 
        }
    }
    
    int findulp(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findulp(parent[node]); 
    }
    
    void unionbysize(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if(ulp_u == ulp_v) return;
        else if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        disjoint ds(26);
            for(auto& equation : equations) {
            if(equation[1] == '=' && equation[2] == '=') {
                int u = equation[0] - 'a';
                int v = equation[3] - 'a';
                ds.unionbysize(u, v);
            }
        }
        for(auto& equation : equations) {
            if(equation[1] == '!' && equation[2] == '=') {
                int u = equation[0] - 'a';
                int v = equation[3] - 'a';
                if(ds.findulp(u) == ds.findulp(v)) {
                    return false;  
                }
            }
        }

        return true;
    }
};
