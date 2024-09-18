class disjoint{
public:
    vector<int> parent;
    vector<int> size;

    disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;  // Initialize the size of each set to 1
        }
    }

    int findulp(int node){
        if(parent[node] == node) return node;
        return parent[node] = findulp(parent[node]);  // Path compression
    }

    void unionbysize(int u, int v){
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if(ulp_u == ulp_v) return;
        
        // Union by size to maintain efficiency
        if(size[ulp_u] < size[ulp_v]){
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        disjoint ds(n);

        // Union the indices according to the pairs
        for(auto& p : pairs){
            ds.unionbysize(p[0], p[1]);
        }

        // Group all indices that are in the same component
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[ds.findulp(i)].push_back(i);
        }

        // For each component, sort the characters and place them back in the string
        for(auto& entry : m){
            vector<int>& indices = entry.second;
            string temp = "";

            // Collect characters of the current component
            for(auto& idx : indices){
                temp += s[idx];
            }

            // Sort the characters in the component
            sort(temp.begin(), temp.end());

            // Put sorted characters back in the original string
            for(int k = 0; k < indices.size(); k++){
                s[indices[k]] = temp[k];
            }
        }

        return s;
    }
};
