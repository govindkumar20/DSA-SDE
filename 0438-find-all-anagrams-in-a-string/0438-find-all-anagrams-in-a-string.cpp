class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //will use sliding window
        vector<int> ans;
        vector<int> goal(26),curr(26);  //for anagram curr==goal
        for(auto i:p) goal[i-'a']++;
        for(int i=0;i<s.size();i++){
            curr[s[i]-'a']++;  // add rightmost to window
            if(i>=p.size()) curr[s[i-p.size()]-'a']--; // remove leftmost from window
            if(goal==curr) ans.push_back(i-p.size()+1); // if condition met insert index into vector

        }
        return ans;
    }
};