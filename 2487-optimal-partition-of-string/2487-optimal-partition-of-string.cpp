class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int ans=1;
        for(auto i:s){
            if(st.find(i)==st.end()) st.insert(i);
            else {
                ans++;
                st.clear();
                st.insert(i);
            }
        }
        return ans;
    }
};