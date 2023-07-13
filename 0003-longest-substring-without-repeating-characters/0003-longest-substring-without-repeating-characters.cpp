class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        set<int> st;
       int  start=0;
       int  end=0;
        int ans=0;
        while(start<n && end<n)
        {
            if(st.find(s[start])==st.end())
            {
                st.insert(s[start]);
                start++;
                ans=max(ans,start-end);
            } else{
                st.erase(s[end]);
                end++;
            }
        }
        return ans;
    }
};