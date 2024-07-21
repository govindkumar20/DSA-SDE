class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> m;
    vector<string> ans; 
    void dfs(string from){
        auto &x=m[from];  // &x refers to the priority queue in reference to m[from]
        while(!x.empty()){
            string to=x.top();  // lexio smallest string
            x.pop(); 
            dfs(to);  // dfs on neighbours of neighbours
        }
        ans.push_back(from); // pushback in ans

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto i:tickets){   // mapping {from,to} 
            m[i[0]].push(i[1]);
        }
        dfs("JFK");  // dfs from starting
        reverse(ans.begin(),ans.end());  // reverse bcz ans is stores in recursion stack in reverse order
        return ans;
    }
};