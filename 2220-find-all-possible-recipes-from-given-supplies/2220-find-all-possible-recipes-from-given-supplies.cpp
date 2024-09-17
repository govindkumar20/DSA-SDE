class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        set<string> s;
        for(auto i:supplies) s.insert(i);
        unordered_map<string,vector<string>> adj;
        map<string,int> indegree;
        for(auto i:recipes) indegree[i]=0;
        //indegree keeps track of how many ingredients each recipe depends on.
        for(int i=0;i<n;i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(s.find(ingredients[i][j])==s.end()){
                    adj[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        //topo
        queue<string> q;
        for(auto i:indegree){
            if(i.second==0) q.push(i.first);
        }
        vector<string> ans;
        while(!q.empty()){
            string node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                if(--indegree[i]==0) q.push(i);
            }
        }
        return ans;

    }
};