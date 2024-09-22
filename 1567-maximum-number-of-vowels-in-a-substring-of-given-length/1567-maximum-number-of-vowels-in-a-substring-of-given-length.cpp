class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> st;
        st.insert('a'); st.insert('e'); st.insert('i'); st.insert('o'); st.insert('u');
        int n=s.size();
        int maxCount=0;
         int count=0;
        for(int i=0;i<k;i++){
            if(st.find(s[i])!=st.end()) count++;
        }
        maxCount=count;
        
        for(int i=k;i<n;i++){
            if(st.find(s[i-k])!=st.end()) count--;
            if(st.find(s[i])!=st.end()) count++;
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};