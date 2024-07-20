// initially i cannot fuckin imagine this is a graph problem


class Solution {
public:
   double dfs(string up, string down, unordered_map<string,unordered_map<string,double>>& m, unordered_set<string>& visited) {
    if(m[up].find(down)!=m[up].end()) return m[up][down];
    for(auto i:m[up]){ // checking neighbours of up
        if(visited.find(i.first)==visited.end()){ // marking neighbours as visited
            visited.insert(i.first);
            double temp=dfs(i.first,down,m,visited);  // if there is a relation btw neighbour and down 
            if(temp) return i.second*temp;
            //   a/b  *  b/c =  a/c
            
        }
    }
    return 0;
   }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> m;
        vector<double> ans;
        for(int i=0;i<values.size();i++){
            m[equations[i][0]].insert({equations[i][1],values[i]});
            m[equations[i][1]].insert({equations[i][0],1/values[i]});
        }
        for(auto i:queries){
            unordered_set<string> visited;
            double temp=dfs(i[0],i[1],m,visited);
            if(temp) ans.push_back(temp);
            else ans.push_back(-1);
        }
        return ans;
    }
};